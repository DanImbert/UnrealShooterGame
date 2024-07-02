// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h" // Include for UInputMappingContext
#include "EnhancedInputComponent.h" // Include for UEnhancedInputComponent
#include "InputAction.h" // Include for UInputAction
#include "EnhancedInputSubSystems.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class DANUNREALSHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

	//Enhanced Input

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* InputMappingContext;
 
	UPROPERTY(EditAnywhere, Category = "Input")
        UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, Category = "Input")
        UInputAction* LookAction;
	
	UPROPERTY(EditAnywhere, Category = "Input")
        UInputAction* LookGamepadAction;
	
	UPROPERTY(EditAnywhere, Category = "Input")
        UInputAction* JumpAction;
 
	UPROPERTY(EditAnywhere, Category = "Input")
	float LookRate = 70.f;
 
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void LookGamepad(const FInputActionValue& Value);

	// End Enhanced Input

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	// void LookUp(float AxisValue);
};
