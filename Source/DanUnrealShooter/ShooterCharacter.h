// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class DANUNREALSHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
     //Spring Arm Component to follow the camera behind the player
     UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
     class USpringArmComponent* SpringArmComp;
 
     //Player follow camera
     UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
     class UCameraComponent* CameraComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Movement functions
    void MoveForward(float Value);
    void MoveRight(float Value);

    // Look functions
    void LookUp(float Value);
    void Turn(float Value);

    // Jumping
    void StartJump();
    void StopJump();

private:
    
    bool bIsJumping;

};
