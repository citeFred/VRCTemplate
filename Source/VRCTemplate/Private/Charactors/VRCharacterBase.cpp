// Fill out your copyright notice in the Description page of Project Settings.


#include "Charactors/VRCharacterBase.h"
#include "Camera/CameraComponent.h"

AVRCharacterBase::AVRCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	Origin->SetupAttachment(GetMesh());

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(Origin);
}

void AVRCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVRCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
