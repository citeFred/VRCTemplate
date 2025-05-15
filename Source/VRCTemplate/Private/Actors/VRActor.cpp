// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/VRActor.h"

AVRActor::AVRActor()
{
	PrimaryActorTick.bCanEverTick = true;

	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>("ActorMesh");
	SetRootComponent(ActorMesh);
}

void AVRActor::BeginPlay()
{
	Super::BeginPlay();
	
}
