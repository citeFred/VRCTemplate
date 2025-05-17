// Fill out your copyright notice in the Description page of Project Settings.

#include "Charactors/VRCharacterBase.h"

// �ʿ��� ��� ���� ���� (��ü���� ��� ��� �� �ʿ�)
#include "Camera/CameraComponent.h" // ī�޶� ������Ʈ ��� ���
#include "Components/InputComponent.h" // SetupPlayerInputComponent���� UInputComponent ���
#include "GameFramework/Controller.h" // Controller (Pawn�� ������) ���� ��� (GetControlRotation ��)
#include "GameFramework/CharacterMovementComponent.h" // AddMovementInput ���
#include "GameFramework/Pawn.h" // AddControllerPitch/YawInput ���
#include "Math/RotationMatrix.h" // FRotationMatrix ��� (������/���� ���� ���� ��)


// ������
AVRCharacterBase::AVRCharacterBase()
{
	// ���Ͱ� �� ������ Tick �Լ��� ȣ������ ����
	PrimaryActorTick.bCanEverTick = true;

	// Origin ������Ʈ ���� �� �޽�(SkeletalMeshComponent)�� ����
	// GetMesh()�� ACharacter�� ��� �Լ���, �⺻ ���̷�Ż �޽� ������Ʈ�� ��ȯ�մϴ�.
	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	Origin->SetupAttachment(GetMesh());

	// Camera ������Ʈ ���� �� Origin ������Ʈ�� ����
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(Origin);

	// ��Ʈ�ѷ�(�÷��̾� ����) ȸ���� ���� ī�޶� ȸ���ϵ��� ���� (���콺 ���� ȸ���� �ʿ�)
	Camera->bUsePawnControlRotation = true;
}

// ���� ���� �� ȣ��Ǵ� �Լ�
void AVRCharacterBase::BeginPlay()
{
	Super::BeginPlay();

}

// �� ������ ȣ��Ǵ� �Լ�
void AVRCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// �Է��� ���ε��ϱ� ���� ȣ��Ǵ� �Լ�
// Project Settings -> Engine -> Input -> Axis Mappings / Action Mappings ���� ������ �̸��� �Լ��� �����մϴ�.
void AVRCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// �θ� Ŭ����(ACharacter)�� SetupPlayerInputComponent ȣ�� (�⺻ �Է� ���ε� ����)
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Axis Mapping ���ε� ���� (Move_Forward, Move_Right, Turn_View, LookUp_View)
	// Project Settings���� �� �̸����� Axis Mapping�� �����Ǿ� �־�� �մϴ�.
	// InputValue (float)�� �ش� ���� �Է� �����Դϴ� (-1.0 ~ 1.0).
	PlayerInputComponent->BindAxis("Move_Forward", this, &AVRCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("Move_Right", this, &AVRCharacterBase::MoveRight);

	// Yaw (�¿� ���� ȸ��) �� Pitch (���� ���� ȸ��) ���ε�
	PlayerInputComponent->BindAxis("Turn_View", this, &AVRCharacterBase::Turn);
	PlayerInputComponent->BindAxis("LookUp_View", this, &AVRCharacterBase::LookUp);

	// Action Mapping ���ε� ���� (Jump)
	// PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump); // ACharacter::Jump ���
	// PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping); // ACharacter::StopJumping ���

	// TODO: Enhanced Input System������ ��ȯ ���
	// �𸮾� ���� 5������ Enhanced Input System ����� ����˴ϴ�.
	// Enhance Input�� ����� ��� �� SetupPlayerInputComponent �Լ��� �ٸ� ������� ���˴ϴ�.
	// (Event BeginPlay���� IMC�� �÷��̾�� �߰��ϰ�, �������Ʈ�� C++���� Enhanced Action Events�� ���� �޴� ���)
}

// WASD ������/�ڷ� �̵� �Է� ó�� �Լ�
void AVRCharacterBase::MoveForward(float InputValue)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);
}

// WASD ����/������ �̵� �Է� ó�� �Լ�
void AVRCharacterBase::MoveRight(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue);
}

// ���콺 �¿� ������ (Yaw) �Է� ó�� �Լ�
void AVRCharacterBase::Turn(float InputValue)
{
	// ��Ʈ�ѷ� Yaw (�¿�) ȸ�� �Է� �߰�
	// �÷��̾��� ����(Controller)�� �¿�� ȸ���ϰ� �մϴ�.
	AddControllerYawInput(InputValue);
}

// ���콺 ���� ������ (Pitch) �Է� ó�� �Լ�
void AVRCharacterBase::LookUp(float InputValue)
{
	// ��Ʈ�ѷ� Pitch (����) ȸ�� �Է� �߰�
	// �÷��̾��� ����(Controller)�� ���Ϸ� ȸ���ϰ� �մϴ�.
	AddControllerPitchInput(InputValue);
}
