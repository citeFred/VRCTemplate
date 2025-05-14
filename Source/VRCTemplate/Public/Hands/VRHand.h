// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VRHand.generated.h"

// Forward declarations
class USkeletalMeshComponent;
class UMotionControllerComponent;
class UWidgetInteractionComponent;
class USphereComponent;


UCLASS()
class VRCTEMPLATE_API AVRHand : public AActor
{
	GENERATED_BODY()
	
public:	
	AVRHand();

protected:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

#pragma region Components
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UMotionControllerComponent> MotionController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components|Hands")
	TObjectPtr<USkeletalMeshComponent> HandMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components|Hands")
	TObjectPtr<UWidgetInteractionComponent> WidgetInteractionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components|Hands")
	TObjectPtr<USphereComponent> GrabSphere;
#pragma endregion

#pragma region HandData
	// Define the hand type (left or right) for the hand mesh
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components|Hands|HandData")
	EControllerHand HandType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components|Hands|HandData")
	bool bMirrorAnimation;
#pragma endregion
private:


};
