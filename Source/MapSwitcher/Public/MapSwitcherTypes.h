#pragma once

#include "CoreMinimal.h"
#include "MapSwitcherSettings.h"

enum class EMapSwitcherEntryStatus : uint8
{
	Valid,
	MissingLevel,
	InvalidLevelPath
};

struct FMapSwitcherResolvedEntry
{
	EMapSwitcherEntryStatus Status = EMapSwitcherEntryStatus::MissingLevel;
	FText Label;
	FText Reason;
	FSoftObjectPath LevelPath;
	FString LevelPackageName;

	bool IsValid() const
	{
		return Status == EMapSwitcherEntryStatus::Valid;
	}
};

class FMapSwitcherEntryUtils
{
public:
	static FMapSwitcherResolvedEntry Resolve(const FMapSwitcherEntry& Entry);
	static FText StatusToReason(EMapSwitcherEntryStatus Status);
};
