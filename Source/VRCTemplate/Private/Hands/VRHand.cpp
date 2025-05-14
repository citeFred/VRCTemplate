// Fill out your copyright notice in the Description page of Project Settings.


#include "Hands/VRHand.h"
#include "Charactors/VRCharacterBase.h"

AVRHand::AVRHand()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AVRHand::BeginPlay()
{
	Super::BeginPlay();
	//AVRCharacterBase Character;
	//Character.var; // Not accessible, protected variable in the base class
	
	//AVRCharacterBase* PointerToCharacter; // Pointer to the character class
	//if (PointerToCharacter) // Check if the pointer is valid
	//	PointerToCharacter->Var; // Accessing the variable through the pointer

}

void AVRHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

