// Fill out your copyright notice in the Description page of Project Settings.


#include "DestroyThemAll.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"


void ADestroyThemAll::PawnKilled(APawn* PawnKilled) 
{
    Super::PawnKilled(PawnKilled);

    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
        EndGame(false); 
    }

    for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
    {
        if (!Controller->IsDead())
        {
            return;
        }
    }
    
    EndGame(true);


}


void ADestroyThemAll::EndGame(bool bIsPlayerWinner) 
{
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}



