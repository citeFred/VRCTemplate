// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/VRActor.h"
#include "VRGrabbableActor.generated.h"

class UBoxComponent;

UCLASS()
class VRCTEMPLATE_API AVRGrabbableActor : public AVRActor
{
	GENERATED_BODY()
	
public:
	AVRGrabbableActor();

protected:

#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent> GrabRegion;

#pragma endregion
};
