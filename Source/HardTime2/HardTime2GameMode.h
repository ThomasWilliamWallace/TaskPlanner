// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SimWorld.h"
#include "GameFramework/GameModeBase.h"
#include "HardTime2GameMode.generated.h"

UCLASS(minimalapi)
class AHardTime2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHardTime2GameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AHardTime2GameMode)
		USimWorld* m_simWorld;
};



