// Fill out your copyright notice in the Description page of Project Settings.


#include "Hands/VRHand.h"
#include "MotionControllerComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "Components/SphereComponent.h"

AVRHand::AVRHand()
{
	PrimaryActorTick.bCanEverTick = true;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>("MotionController");
	SetRootComponent(MotionController);

	HandMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HandMesh");
	HandMesh->SetupAttachment(MotionController);

	WidgetInteractionComponent = CreateDefaultSubobject<UWidgetInteractionComponent>("WidgetInteraction");
	WidgetInteractionComponent->SetupAttachment(HandMesh);

	GrabSphere = CreateDefaultSubobject<USphereComponent>("GrabSphere");
	WidgetInteractionComponent->SetupAttachment(HandMesh);
}

void AVRHand::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	switch (HandType) // Set the hand type
	{
	case EControllerHand::Left:
		MotionController->MotionSource = "Left";
		break;
	case EControllerHand::Right:
		MotionController->MotionSource = "Right";
		break;
	default:

		break;
	}
}

void AVRHand::BeginPlay()  
{  
    Super::BeginPlay();  

	if(HandType != EControllerHand::Left && HandType != EControllerHand::Right)
	{
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
				FString::Printf(TEXT("Invalid hand type set for %s. Defaulting to left hand."), *GetName())
			);
		}
	}
}

void AVRHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVRHand::GrabObject()
{
	TArray<AActor*> OverlappingActors;
	GrabSphere->GetOverlappingActors(OverlappingActors);

	if (!OverlappingActors.IsEmpty())
	{
		AActor* FirstActorUnderCollision = OverlappingActors[0];
		if (FirstActorUnderCollision)
		{
			CurrentlyGrabbedActor = TScriptInterface<IInteractInterface>(FirstActorUnderCollision);
			if (CurrentlyGrabbedActor)
			{
				CurrentlyGrabbedActor->OnGrab(HandMesh, HandMesh->GetComponentLocation());
			}
		}
	}
}

void AVRHand::ReleaseObject()
{
	if (CurrentlyGrabbedActor)
	{
		CurrentlyGrabbedActor->OnRelease(HandMesh);
		CurrentlyGrabbedActor = nullptr;
	}
}

