#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Engine/World.h"
#include "MapSwitcherSettings.generated.h"

USTRUCT(BlueprintType)
struct MAPSWITCHER_API FMapSwitcherEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Config, Category = "Map Switcher", meta = (DisplayName = "Name"))
	FString DisplayName;

	UPROPERTY(EditAnywhere, Config, Category = "Map Switcher", meta = (AllowedClasses = "/Script/Engine.World", DisplayName = "Level"))
	TSoftObjectPtr<UWorld> Level;
};

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Map Switcher"))
class MAPSWITCHER_API UMapSwitcherSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	virtual FName GetContainerName() const override;
	virtual FName GetCategoryName() const override;
	virtual FName GetSectionName() const override;

#if WITH_EDITOR
	virtual FText GetSectionText() const override;
	virtual FText GetSectionDescription() const override;
#endif

	UPROPERTY(EditAnywhere, Config, Category = "Map Switcher", meta = (TitleProperty = "DisplayName"))
	TArray<FMapSwitcherEntry> Levels;
};
