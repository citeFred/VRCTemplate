#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KeyboardCharacter.generated.h"

UCLASS()
class VRCTEMPLATE_API AKeyboardCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AKeyboardCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent* Camera;

	void MoveForward(float InputValue);
	void MoveRight(float InputValue);
	void Turn(float InputValue);
	void LookUp(float InputValue);
};
