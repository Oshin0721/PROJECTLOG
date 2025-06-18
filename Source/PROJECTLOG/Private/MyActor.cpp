// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	start = FVector2D(0, 0);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Starting position: (%.0f, %.0f)"), start.X, start.Y);
	move();

	for (int i = 0; i < Path.Num(); ++i)
	{
		UE_LOG(LogTemp, Warning, TEXT("Path[%d]: X=%.0f, Y=%.0f"), i, Path[i].X, Path[i].Y);
	}
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

void AMyActor::TriggerEventWithProbability(float Probability)
{
	int32 RandomValue = FMath::RandRange(1, 100);
	if (RandomValue <= Probability)
	{
		UE_LOG(LogTemp, Log, TEXT(">> 🎉 Event Triggered!"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT(">> Event Skipped."));
	}
}

void AMyActor::move()
{
	for (int i = 0; i < 10; ++i)
	{
		int deltaX = step();
		int deltaY = step();

		start.X += deltaX;
		start.Y += deltaY;
		
		Path.Add(start);

		float dist = FVector2D::Distance(FVector2D(0, 0), start);

		UE_LOG(LogTemp, Warning, TEXT("Step %d: Moved to (%.0f, %.0f), Distance from origin: %.2f"), i + 1, start.X, start.Y, dist);
	
		TriggerEventWithProbability(25.0f);
	}
}

