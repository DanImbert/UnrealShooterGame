// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
 


// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	 // Instantiating your class Components
 
     SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
 
     CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
 
     //Set the location and rotation of the Character Mesh Transform
 
     GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -90.0f), FQuat(FRotator(0.0f, -90.0f, 0.0f)));
 
     // Attaching your class Components to the default character's Skeletal Mesh Component.
 
     SpringArmComp->SetupAttachment(GetMesh());
 
     CameraComp->SetupAttachment(SpringArmComp,USpringArmComponent::SocketName);
 
     //Setting class variables of the spring arm
 
     SpringArmComp->bUsePawnControlRotation = true;
 
     //Setting class variables of the Character movement component
 
     GetCharacterMovement()->bOrientRotationToMovement = true;
 
     GetCharacterMovement()->bUseControllerDesiredRotation = true;
 
     GetCharacterMovement()->bIgnoreBaseRotation = true;
 

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

