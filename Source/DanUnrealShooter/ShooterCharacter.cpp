#include "ShooterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Initialize components
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
    SpringArmComp->SetupAttachment(GetMesh()); // Assuming you want to attach to character mesh
    SpringArmComp->bUsePawnControlRotation = true;

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
    CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);

    // Set up character movement
    GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
    GetCharacterMovement()->JumpZVelocity = 600.f;
    GetCharacterMovement()->AirControl = 0.2f;

    // Initialize jump state
    bIsJumping = false;
    bPressedJump = false;
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

    // Bind movement and look inputs
    PlayerInputComponent->BindAxis("MoveForward", this, &AShooterCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AShooterCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &AShooterCharacter::LookUp);
    PlayerInputComponent->BindAxis("Turn", this, &AShooterCharacter::Turn);

    // Bind jump input
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AShooterCharacter::StartJump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &AShooterCharacter::StopJump);
}

void AShooterCharacter::MoveForward(float Value)
{
    if (Controller != nullptr && Value != 0.0f)
    {
        // Find out which way is forward
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void AShooterCharacter::MoveRight(float Value)
{
    if (Controller != nullptr && Value != 0.0f)
    {
        // Find out which way is right
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void AShooterCharacter::LookUp(float Value)
{
    AddControllerPitchInput(Value);
}

void AShooterCharacter::Turn(float Value)
{
    AddControllerYawInput(Value);
}

void AShooterCharacter::StartJump()
{
    bIsJumping = true;
    bPressedJump = true;
}

void AShooterCharacter::StopJump()
{
    bIsJumping = false;
    bPressedJump = false;
}
