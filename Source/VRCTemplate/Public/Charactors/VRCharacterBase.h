// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacterBase.generated.h"

// 컴포넌트 클래스들의 전방 선언
// 헤더 파일에서는 포인터/참조만 선언할 경우 전방 선언을 사용하는 것이 컴파일 시간 단축에 유리합니다.
class UCameraComponent;
class USceneComponent;
class UInputComponent; // SetupPlayerInputComponent 함수의 매개변수 타입

UCLASS()
class VRCTEMPLATE_API AVRCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// 생성자
	AVRCharacterBase();

protected:
	// 게임 시작 시 호출됩니다.
	virtual void BeginPlay() override;

	// 매 프레임 호출됩니다.
	virtual void Tick(float DeltaTime) override;

	// 입력을 바인딩하기 위해 호출됩니다.
	// C++ Input Binding (SetupPlayerInputComponent 사용) 방식에서 필요합니다.
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// WASD 이동 입력 처리 함수
	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	// 마우스 시점 회전 입력 처리 함수 (Yaw, Pitch)
	void Turn(float InputValue);
	void LookUp(float InputValue);


	// 카메라 컴포넌트 선언
	// UPROPERTY 매크로는 언리얼 엔진의 리플렉션 시스템에 노출시켜 에디터에서 보거나 조작 가능하게 합니다.
	// VisibleAnywhere: 에디터의 Details 패널에서 볼 수 있습니다.
	// BlueprintReadOnly: 블루프린트에서 값을 읽을 수 있습니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components|Camera")
	TObjectPtr<UCameraComponent> Camera;

	// VR 뷰포트의 오리진(중심) 역할을 할 씬 컴포넌트 선언
	// 보통 HMD 트래킹 데이터가 이 컴포넌트에 적용되고, 카메라는 이 컴포넌트의 자식으로 붙습니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components|VR")
	TObjectPtr<USceneComponent> Origin;


private:
	// 필요한 경우 여기에 Private 멤버 변수나 함수를 선언합니다.

};
