// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacterBase.generated.h"

UCLASS()
class VRCTEMPLATE_API AVRCharacterBase : public ACharacter
{
	GENERATED_BODY()

	// Scopes: Public, Protected, Private
public:
	AVRCharacterBase(); // Constructor	
	int32 Var; // Variable definition


protected:
	virtual void BeginPlay() override; // Prototype for BeginPlay function
	int var = 32;

public:	
	virtual void Tick(float DeltaTime) override; // Prototype for Tick function

	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

};
