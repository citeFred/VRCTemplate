// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/VRActor.h"
#include "Interfaces/InteractInterface.h"
#include "VRGrabbableActor.generated.h"

class UBoxComponent;

UENUM(BlueprintType)
enum class EGrabType:uint8
{
	Free,
	Snap,
	None
};

UCLASS()
class VRCTEMPLATE_API AVRGrabbableActor : public AVRActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:
	AVRGrabbableActor();

protected:
	virtual void OnGrab(USkeletalMeshComponent* InComponent, const FVector& GrabLocation); // From InteractInterface
	virtual void OnRelease(USkeletalMeshComponent* InComponent); // From InteractInterface

#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent> GrabRegion;
#pragma endregion

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Setup")
	EGrabType GrabType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	bool bIsHeld;

private:
	USkeletalMeshComponent* GrabbedBySkeletalMesh;
};
