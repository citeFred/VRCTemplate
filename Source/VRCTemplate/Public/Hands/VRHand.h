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

	// **Add, Adjust custom component in C++ into Blueprint**

	// [1-2] Add MotionControllerComponent to the class
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")	// added to make it visible in the editor
	TObjectPtr<UMotionControllerComponent> MotionController;

	// [2-1] Add a SkeletalMeshComponent to the class (It's Include in "CoreMinimal.h")
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components|Hands")
	TObjectPtr<USkeletalMeshComponent> HandMesh;

	// [3-2] Add a WidgetInteractionComponent to the class
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components|Hands")
	TObjectPtr<UWidgetInteractionComponent> WidgetInteractionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components|Hands")
	TObjectPtr<USphereComponent> GrabSphere; // [4-1] Add a SphereComponent to the class (It's Include in "CoreMinimal.h")

private:


};
