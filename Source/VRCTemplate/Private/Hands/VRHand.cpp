// Fill out your copyright notice in the Description page of Project Settings.


#include "Hands/VRHand.h"

AVRHand::AVRHand()
{
	PrimaryActorTick.bCanEverTick = true;
	// **Add, Adjust custom component in C++ into Blueprint**

	// [1-3] Add MotionControllerComponent follow up header file
	MotionController = CreateDefaultSubobject<UMotionControllerComponent>("MotionController");
	SetRootComponent(MotionController); // [1-4]. Set MotionController as RootComponent

	// [2-2] Add SkeletalMeshComponent follow up header file
	HandMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HandMesh");
	HandMesh->SetupAttachment(MotionController); // [2-3] Attach HandMesh to MotionController

	// [3-3] Add WidgetInteractionComponent follow up header file
	WidgetInteractionComponent = CreateDefaultSubobject<UWidgetInteractionComponent>("WidgetInteractionComponent");
	WidgetInteractionComponent->SetupAttachment(HandMesh); // [3-4] Attach WidgetInteractionComponent to HandMesh

	// [4-2] Add VRGripInterface follow up header file
	GrabSphere = CreateDefaultSubobject<USphereComponent>("GrabSphere");
	GrabSphere->SetupAttachment(HandMesh); // [4-3] Attach GrabSphere to HandMesh

}

void AVRHand::BeginPlay()  
{  
    Super::BeginPlay();  
}

void AVRHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

