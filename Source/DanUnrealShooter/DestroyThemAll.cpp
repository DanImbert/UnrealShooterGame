// Fill out your copyright notice in the Description page of Project Settings.


#include "DestroyThemAll.h"

void ADestroyThemAll::PawnKilled(APawn* PawnKilled) 
{
    Super::PawnKilled(PawnKilled);

    UE_LOG(LogTemp, Warning, TEXT("A pawn was killed!"));
}


