#include "MapSwitcherModule.h"

#include "Editor.h"
#include "FileHelpers.h"
#include "Styling/AppStyle.h"
#include "Framework/Notifications/NotificationManager.h"
#include "MapSwitcherSettings.h"
#include "MapSwitcherTypes.h"
#include "ToolMenu.h"
#include "ToolMenuEntry.h"
#include "ToolMenuSection.h"
#include "ToolMenus.h"
#include "Widgets/Notifications/SNotificationList.h"

#define LOCTEXT_NAMESPACE "FMapSwitcherModule"

class FMapSwitcherModule : public IMapSwitcherModule
{
public:
	virtual void StartupModule() override
	{
		UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMapSwitcherModule::RegisterMenus));
	}

	virtual void ShutdownModule() override
	{
		if (UObjectInitialized())
		{
			UToolMenus::UnRegisterStartupCallback(this);
			UToolMenus::UnregisterOwner(this);
		}
	}

private:
	void RegisterMenus()
	{
		FToolMenuOwnerScoped OwnerScoped(this);

		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		if (!ToolbarMenu)
		{
			ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		}

		if (!ToolbarMenu)
		{
			return;
		}

		FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("MapSwitcher");
		FToolMenuEntry Entry = FToolMenuEntry::InitComboButton(
			"MapSwitcher_Dropdown",
			FUIAction(),
			FOnGetContent::CreateRaw(this, &FMapSwitcherModule::GenerateMapSwitcherMenu),
			FText::FromString(TEXT("\u8DF3\u8F6C\u573A\u666F")),
			LOCTEXT("MapSwitcherTooltip", "Open a configured editor level."),
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Levels"));
		Entry.SetCommandList(nullptr);
		Section.AddEntry(Entry);
	}

	TSharedRef<SWidget> GenerateMapSwitcherMenu()
	{
		FToolMenuContext Context;
		UToolMenu* Menu = UToolMenus::Get()->RegisterMenu(
			"MapSwitcher.Dropdown",
			NAME_None,
			EMultiBoxType::Menu,
			false);

		Menu->RemoveSection("MapSwitcherLevels");
		FToolMenuSection& Section = Menu->AddSection("MapSwitcherLevels", LOCTEXT("MapSwitcherLevelsSection", "Configured Levels"));

		const UMapSwitcherSettings* Settings = GetDefault<UMapSwitcherSettings>();
		if (!Settings || Settings->Levels.IsEmpty())
		{
			FToolMenuEntry EmptyEntry = FToolMenuEntry::InitMenuEntry(
				"MapSwitcher_NoLevels",
				LOCTEXT("NoLevelsLabel", "No configured levels"),
				LOCTEXT("NoLevelsTooltip", "Add levels in Project Settings > Plugins > Map Switcher."),
				FSlateIcon(),
				FUIAction(FExecuteAction(), FCanExecuteAction::CreateLambda([] { return false; })));
			Section.AddEntry(EmptyEntry);
			return UToolMenus::Get()->GenerateWidget(Menu);
		}

		for (int32 Index = 0; Index < Settings->Levels.Num(); ++Index)
		{
			const FMapSwitcherEntry& ConfiguredEntry = Settings->Levels[Index];
			const FMapSwitcherResolvedEntry Resolved = FMapSwitcherEntryUtils::Resolve(ConfiguredEntry);
			const FName EntryName(*FString::Printf(TEXT("MapSwitcher_Level_%d"), Index));

			if (!Resolved.IsValid())
			{
				FToolMenuEntry InvalidEntry = FToolMenuEntry::InitMenuEntry(
					EntryName,
					Resolved.Label,
					Resolved.Reason,
					FSlateIcon(),
					FUIAction(FExecuteAction(), FCanExecuteAction::CreateLambda([] { return false; })));
				Section.AddEntry(InvalidEntry);
				continue;
			}

			FToolMenuEntry LevelEntry = FToolMenuEntry::InitMenuEntry(
				EntryName,
				Resolved.Label,
				FText::Format(LOCTEXT("OpenLevelTooltip", "Open {0}."), FText::FromString(Resolved.LevelPath.GetAssetPathString())),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Levels"),
				FUIAction(FExecuteAction::CreateRaw(this, &FMapSwitcherModule::OpenConfiguredLevel, ConfiguredEntry)));
			Section.AddEntry(LevelEntry);
		}

		return UToolMenus::Get()->GenerateWidget(Menu);
	}

	void OpenConfiguredLevel(FMapSwitcherEntry ConfiguredEntry)
	{
		if (GEditor && GEditor->PlayWorld)
		{
			ShowNotification(LOCTEXT("CannotOpenDuringPIE", "Stop Play/Simulate before jumping to another scene."), SNotificationItem::CS_Fail);
			return;
		}

		const FMapSwitcherResolvedEntry Resolved = FMapSwitcherEntryUtils::Resolve(ConfiguredEntry);
		if (!Resolved.IsValid())
		{
			ShowNotification(
				FText::Format(LOCTEXT("InvalidLevelNotification", "Cannot open scene: {0}"), Resolved.Reason),
				SNotificationItem::CS_Fail);
			return;
		}

		if (!FEditorFileUtils::LoadMap(Resolved.LevelPackageName, false, true))
		{
			ShowNotification(
				FText::Format(LOCTEXT("FailedToOpenLevel", "Failed to open scene: {0}"), FText::FromString(Resolved.LevelPackageName)),
				SNotificationItem::CS_Fail);
		}
	}

	void ShowNotification(const FText& Message, SNotificationItem::ECompletionState CompletionState) const
	{
		FNotificationInfo Info(Message);
		Info.ExpireDuration = 4.0f;
		Info.bUseSuccessFailIcons = true;

		TSharedPtr<SNotificationItem> Notification = FSlateNotificationManager::Get().AddNotification(Info);
		if (Notification.IsValid())
		{
			Notification->SetCompletionState(CompletionState);
		}
	}
};

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMapSwitcherModule, MapSwitcher)
