#include "MapSwitcherTypes.h"

#include "Misc/PackageName.h"

#define LOCTEXT_NAMESPACE "MapSwitcherTypes"

FMapSwitcherResolvedEntry FMapSwitcherEntryUtils::Resolve(const FMapSwitcherEntry& Entry)
{
	FMapSwitcherResolvedEntry Resolved;
	Resolved.LevelPath = Entry.Level.ToSoftObjectPath();

	if (Resolved.LevelPath.IsNull())
	{
		Resolved.Status = EMapSwitcherEntryStatus::MissingLevel;
		Resolved.Label = Entry.DisplayName.TrimStartAndEnd().IsEmpty()
			? LOCTEXT("UnnamedMissingLevel", "Unnamed Level")
			: FText::FromString(Entry.DisplayName);
		Resolved.Reason = StatusToReason(Resolved.Status);
		return Resolved;
	}

	Resolved.LevelPackageName = Resolved.LevelPath.GetLongPackageName();
	if (Resolved.LevelPackageName.IsEmpty() || !FPackageName::IsValidLongPackageName(Resolved.LevelPackageName))
	{
		Resolved.Status = EMapSwitcherEntryStatus::InvalidLevelPath;
		Resolved.Label = Entry.DisplayName.TrimStartAndEnd().IsEmpty()
			? FText::FromString(Resolved.LevelPath.GetAssetName())
			: FText::FromString(Entry.DisplayName);
		Resolved.Reason = StatusToReason(Resolved.Status);
		return Resolved;
	}

	Resolved.Status = EMapSwitcherEntryStatus::Valid;
	Resolved.Label = Entry.DisplayName.TrimStartAndEnd().IsEmpty()
		? FText::FromString(Resolved.LevelPath.GetAssetName())
		: FText::FromString(Entry.DisplayName);
	Resolved.Reason = FText::GetEmpty();
	return Resolved;
}

FText FMapSwitcherEntryUtils::StatusToReason(EMapSwitcherEntryStatus Status)
{
	switch (Status)
	{
	case EMapSwitcherEntryStatus::Valid:
		return FText::GetEmpty();
	case EMapSwitcherEntryStatus::MissingLevel:
		return LOCTEXT("MissingLevelReason", "No level asset is assigned.");
	case EMapSwitcherEntryStatus::InvalidLevelPath:
		return LOCTEXT("InvalidLevelPathReason", "The configured level path is not a valid Unreal package path.");
	default:
		return LOCTEXT("UnknownEntryReason", "The configured level entry is invalid.");
	}
}

#undef LOCTEXT_NAMESPACE
