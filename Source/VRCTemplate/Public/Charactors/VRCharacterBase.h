// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacterBase.generated.h"

// ������Ʈ Ŭ�������� ���� ����
// ��� ���Ͽ����� ������/������ ������ ��� ���� ������ ����ϴ� ���� ������ �ð� ���࿡ �����մϴ�.
class UCameraComponent;
class USceneComponent;
class UInputComponent; // SetupPlayerInputComponent �Լ��� �Ű����� Ÿ��

UCLASS()
class VRCTEMPLATE_API AVRCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// ������
	AVRCharacterBase();

protected:
	// ���� ���� �� ȣ��˴ϴ�.
	virtual void BeginPlay() override;

	// �� ������ ȣ��˴ϴ�.
	virtual void Tick(float DeltaTime) override;

	// �Է��� ���ε��ϱ� ���� ȣ��˴ϴ�.
	// C++ Input Binding (SetupPlayerInputComponent ���) ��Ŀ��� �ʿ��մϴ�.
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// WASD �̵� �Է� ó�� �Լ�
	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	// ���콺 ���� ȸ�� �Է� ó�� �Լ� (Yaw, Pitch)
	void Turn(float InputValue);
	void LookUp(float InputValue);


	// ī�޶� ������Ʈ ����
	// UPROPERTY ��ũ�δ� �𸮾� ������ ���÷��� �ý��ۿ� ������� �����Ϳ��� ���ų� ���� �����ϰ� �մϴ�.
	// VisibleAnywhere: �������� Details �гο��� �� �� �ֽ��ϴ�.
	// BlueprintReadOnly: �������Ʈ���� ���� ���� �� �ֽ��ϴ�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components|Camera")
	TObjectPtr<UCameraComponent> Camera;

	// VR ����Ʈ�� ������(�߽�) ������ �� �� ������Ʈ ����
	// ���� HMD Ʈ��ŷ �����Ͱ� �� ������Ʈ�� ����ǰ�, ī�޶�� �� ������Ʈ�� �ڽ����� �ٽ��ϴ�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components|VR")
	TObjectPtr<USceneComponent> Origin;


private:
	// �ʿ��� ��� ���⿡ Private ��� ������ �Լ��� �����մϴ�.

};
