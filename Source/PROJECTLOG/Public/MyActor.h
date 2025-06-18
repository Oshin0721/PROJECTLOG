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
	FVector2D start;     // 현재 좌표
	int32 evCnt;         // 이벤트 발생 횟수
	float totDist;       // 누적 거리

	int32 step();        // 0 또는 1 반환
	void move();         // 이동 로직
	int32 createEvent(); // 이벤트 발생 여부 리턴 (50%)
	float distance(FVector2D first, FVector2D second); // 거리 계산
};
