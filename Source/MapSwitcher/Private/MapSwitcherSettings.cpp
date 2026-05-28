#include "MapSwitcherSettings.h"

#define LOCTEXT_NAMESPACE "MapSwitcherSettings"

FName UMapSwitcherSettings::GetContainerName() const
{
	return "Project";
}

FName UMapSwitcherSettings::GetCategoryName() const
{
	return "Plugins";
}

FName UMapSwitcherSettings::GetSectionName() const
{
	return "MapSwitcher";
}

#if WITH_EDITOR
FText UMapSwitcherSettings::GetSectionText() const
{
	return LOCTEXT("MapSwitcherSectionText", "Map Switcher");
}

FText UMapSwitcherSettings::GetSectionDescription() const
{
	return LOCTEXT("MapSwitcherSectionDescription", "Configure levels shown in the editor toolbar map-switcher dropdown.");
}
#endif

#undef LOCTEXT_NAMESPACE
