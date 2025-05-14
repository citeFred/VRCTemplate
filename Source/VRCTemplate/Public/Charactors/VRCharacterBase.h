// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacterBase.generated.h"

class UCameraComponent;

UCLASS()
class VRCTEMPLATE_API AVRCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AVRCharacterBase(); // Constructor	

protected:
	virtual void BeginPlay() override; // Prototype for BeginPlay function
	virtual void Tick(float DeltaTime) override; // Prototype for Tick function

	// Camera component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UCameraComponent> Camera;

	// Viewport origin component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USceneComponent> Origin;
private:

};
