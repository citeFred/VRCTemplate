// Fill out your copyright notice in the Description page of Project Settings.

#include "Charactors/VRCharacterBase.h"

// 필요한 헤더 파일 포함 (구체적인 기능 사용 시 필요)
#include "Camera/CameraComponent.h" // 카메라 컴포넌트 기능 사용
#include "Components/InputComponent.h" // SetupPlayerInputComponent에서 UInputComponent 사용
#include "GameFramework/Controller.h" // Controller (Pawn의 소유자) 정보 사용 (GetControlRotation 등)
#include "GameFramework/CharacterMovementComponent.h" // AddMovementInput 사용
#include "GameFramework/Pawn.h" // AddControllerPitch/YawInput 사용
#include "Math/RotationMatrix.h" // FRotationMatrix 사용 (오른쪽/위쪽 벡터 얻을 때)


// 생성자
AVRCharacterBase::AVRCharacterBase()
{
	// 액터가 매 프레임 Tick 함수를 호출할지 설정
	PrimaryActorTick.bCanEverTick = true;

	// Origin 컴포넌트 생성 및 메시(SkeletalMeshComponent)에 부착
	// GetMesh()는 ACharacter의 멤버 함수로, 기본 스켈레탈 메시 컴포넌트를 반환합니다.
	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	Origin->SetupAttachment(GetMesh());

	// Camera 컴포넌트 생성 및 Origin 컴포넌트에 부착
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(Origin);

	// 컨트롤러(플레이어 시점) 회전에 따라 카메라가 회전하도록 설정 (마우스 시점 회전에 필요)
	Camera->bUsePawnControlRotation = true;
}

// 게임 시작 시 호출되는 함수
void AVRCharacterBase::BeginPlay()
{
	Super::BeginPlay();

}

// 매 프레임 호출되는 함수
void AVRCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// 입력을 바인딩하기 위해 호출되는 함수
// Project Settings -> Engine -> Input -> Axis Mappings / Action Mappings 에서 설정된 이름과 함수를 연결합니다.
void AVRCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// 부모 클래스(ACharacter)의 SetupPlayerInputComponent 호출 (기본 입력 바인딩 유지)
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Axis Mapping 바인딩 예시 (Move_Forward, Move_Right, Turn_View, LookUp_View)
	// Project Settings에서 이 이름으로 Axis Mapping이 설정되어 있어야 합니다.
	// InputValue (float)는 해당 축의 입력 강도입니다 (-1.0 ~ 1.0).
	PlayerInputComponent->BindAxis("Move_Forward", this, &AVRCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("Move_Right", this, &AVRCharacterBase::MoveRight);

	// Yaw (좌우 시점 회전) 및 Pitch (상하 시점 회전) 바인딩
	PlayerInputComponent->BindAxis("Turn_View", this, &AVRCharacterBase::Turn);
	PlayerInputComponent->BindAxis("LookUp_View", this, &AVRCharacterBase::LookUp);

	// Action Mapping 바인딩 예시 (Jump)
	// PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump); // ACharacter::Jump 사용
	// PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping); // ACharacter::StopJumping 사용

	// TODO: Enhanced Input System으로의 전환 고려
	// 언리얼 엔진 5에서는 Enhanced Input System 사용이 권장됩니다.
	// Enhance Input을 사용할 경우 이 SetupPlayerInputComponent 함수는 다른 방식으로 사용됩니다.
	// (Event BeginPlay에서 IMC를 플레이어에게 추가하고, 블루프린트나 C++에서 Enhanced Action Events를 직접 받는 방식)
}

// WASD 앞으로/뒤로 이동 입력 처리 함수
void AVRCharacterBase::MoveForward(float InputValue)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);
}

// WASD 왼쪽/오른쪽 이동 입력 처리 함수
void AVRCharacterBase::MoveRight(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue);
}

// 마우스 좌우 움직임 (Yaw) 입력 처리 함수
void AVRCharacterBase::Turn(float InputValue)
{
	// 컨트롤러 Yaw (좌우) 회전 입력 추가
	// 플레이어의 시점(Controller)이 좌우로 회전하게 합니다.
	AddControllerYawInput(InputValue);
}

// 마우스 상하 움직임 (Pitch) 입력 처리 함수
void AVRCharacterBase::LookUp(float InputValue)
{
	// 컨트롤러 Pitch (상하) 회전 입력 추가
	// 플레이어의 시점(Controller)이 상하로 회전하게 합니다.
	AddControllerPitchInput(InputValue);
}
