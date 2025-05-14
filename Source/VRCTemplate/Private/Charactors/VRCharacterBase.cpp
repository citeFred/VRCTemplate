// Fill out your copyright notice in the Description page of Project Settings.


#include "Charactors/VRCharacterBase.h"

AVRCharacterBase::AVRCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AVRCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	var; // protected access
	
}

void AVRCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AVRCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

