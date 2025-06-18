// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	start = FVector2D(0, 0);
	evCnt = 0;
	totDist = 0.0f;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Start Position: (%.0f, %.0f)"), start.X, start.Y);
	move();

	UE_LOG(LogTemp, Warning, TEXT("Total Distance Moved: %.2f"), totDist);
	UE_LOG(LogTemp, Warning, TEXT("Total Events Triggered: %d"), evCnt);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AMyActor::step()
{
	return FMath::RandRange(0, 1); 
}

int32 AMyActor::createEvent()
{
	int32 random = FMath::RandRange(1, 100);
	if (random <= 50)
	{
		UE_LOG(LogTemp, Log, TEXT(">> Event Triggered!"));
		return 1;
	}
	return 0;
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(FMath::Square(dx) + FMath::Square(dy));
}

void AMyActor::move()
{
	for (int i = 0; i < 10; ++i)
	{
		FVector2D prev = start;

		start.X += step();
		start.Y += step();

		float dist = distance(prev, start);
		totDist += dist;

		evCnt += createEvent();

		UE_LOG(LogTemp, Warning, TEXT("Step %d: New Pos = (%.0f, %.0f), Moved = %.2f"), i + 1, start.X, start.Y, dist);
	}
}
