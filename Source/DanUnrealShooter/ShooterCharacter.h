// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h" // Include for UInputMappingContext
#include "EnhancedInputComponent.h" // Include for UEnhancedInputComponent
#include "InputAction.h" // Include for UInputAction
#include "EnhancedInputSubsystems.h" // Corrected from EnhancedInputSubSystems to EnhancedInputSubsystems
#include "ShooterCharacter.generated.h"


class AGun;

UCLASS()
class DANUNREALSHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;


	// Enhanced Input
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
	UInputAction* ShootAction;
 
	UPROPERTY(EditAnywhere, Category = "Input")
	float LookRate = 70.f;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
	float Health;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	UFUNCTION(BlueprintPure)
	bool IsDead() const; 

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Shoot();

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
    void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);
	

	UPROPERTY(EditAnywhere)
	float RotationRate = 10;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;

	//Enhanced Input

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void LookGamepad(const FInputActionValue& Value);
	void ShootEI();
};
