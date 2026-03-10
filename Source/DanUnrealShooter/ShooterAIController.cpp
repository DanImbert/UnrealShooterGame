// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BrainComponent.h"
#include "ShooterCharacter.h"


void AShooterAIController::BeginPlay() 
{
    Super::BeginPlay();
    
    if (AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);

        APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
    }

   

   

}

 void AShooterAIController::Tick(float DeltaSeconds) 
{
    Super::Tick(DeltaSeconds);
    
    
    
}

bool AShooterAIController::IsDead() const
{
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if (ControlledCharacter != nullptr)
    {
        return ControlledCharacter->IsDead();
    }

    return true;
}

void AShooterAIController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    if (UBrainComponent* BrainComp = GetBrainComponent())
    {
        BrainComp->StopLogic(TEXT("Game has ended"));
    }

    StopMovement();

    if (APawn* ControlledPawn = GetPawn())
    {
        ControlledPawn->TurnOff();
    }

    SetActorTickEnabled(false);
}



