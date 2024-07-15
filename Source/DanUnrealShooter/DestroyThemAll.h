// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterGameModeBase.h"
#include "DestroyThemAll.generated.h"

/**
 * 
 */
UCLASS()
class DANUNREALSHOOTER_API ADestroyThemAll : public AShooterGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void PawnKilled(APawn* PawnKilled) override;

	
};
