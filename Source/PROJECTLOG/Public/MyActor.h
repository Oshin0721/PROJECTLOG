// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class PROJECTLOG_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	FVector2D start;     // ���� ��ǥ
	int32 evCnt;         // �̺�Ʈ �߻� Ƚ��
	float totDist;       // ���� �Ÿ�

	int32 step();        // 0 �Ǵ� 1 ��ȯ
	void move();         // �̵� ����
	int32 createEvent(); // �̺�Ʈ �߻� ���� ���� (50%)
	float distance(FVector2D first, FVector2D second); // �Ÿ� ���
};
