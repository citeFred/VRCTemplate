// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/VRGrabbableActor.h"
#include "Components/BoxComponent.h"

AVRGrabbableActor::AVRGrabbableActor()
{
	GrabRegion = CreateDefaultSubobject<UBoxComponent>("GrabBoxRegion");
	GrabRegion->SetupAttachment(ActorMesh);

	GrabRegion->SetCollisionProfileName("Grabbable");
}

void AVRGrabbableActor::OnGrab(USkeletalMeshComponent* InComponent, const FVector& GrabLocation)
{
	if(InComponent){
		switch (GrabType)
		{
		case EGrabType::Free:
			ActorMesh->SetSimulatePhysics(false);
			bIsHeld = ActorMesh->AttachToComponent(InComponent, FAttachmentTransformRules::KeepWorldTransform);
			if (bIsHeld) {
				GrabbedBySkeletalMesh = InComponent;
			}
			break;
		case EGrabType::Snap:
			break;
		case EGrabType::None:
			break;
		}
	}
}

void AVRGrabbableActor::OnRelease(USkeletalMeshComponent* InComponent)
{
	if (InComponent) {
		switch (GrabType)
		{
		case EGrabType::Free:
			if (bIsHeld) {
				if (InComponent == GrabbedBySkeletalMesh) {
					ActorMesh->SetSimulatePhysics(true);
					bIsHeld = false;
				}
			}
			break;
		case EGrabType::Snap:
			break;
		case EGrabType::None:
			break;
		}
	}
}