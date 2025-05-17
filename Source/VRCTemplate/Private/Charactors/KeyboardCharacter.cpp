#include "Charactors/KeyboardCharacter.h"
#include "Camera/CameraComponent.h"

AKeyboardCharacter::AKeyboardCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>("Keyboard Player Camera");
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true; // Rotate camera with controller
}

void AKeyboardCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AKeyboardCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKeyboardCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AKeyboardCharacter::Jump);
	PlayerInputComponent->BindAxis("Move_Forward", this, &AKeyboardCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move_Right", this, &AKeyboardCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn_View", this, &AKeyboardCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp_View", this, &AKeyboardCharacter::LookUp);
}

void AKeyboardCharacter::MoveForward(float InputValue)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);
}

void AKeyboardCharacter::MoveRight(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue); 
}

void AKeyboardCharacter::Turn(float InputValue)
{
	AddControllerYawInput(InputValue);
}
void AKeyboardCharacter::LookUp(float InputValue)
{
	AddControllerPitchInput(InputValue);
}

