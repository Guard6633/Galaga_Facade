// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementBossComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UMovementBossComponent::UMovementBossComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	/*CurrentVelocity = FVector(0.0f, 0.0f, 0.0f);
	Amplitude = 0.0f;
	Frequency = 0.0f;*/
}


// Called when the game starts
void UMovementBossComponent::BeginPlay()
{
	Super::BeginPlay();

	//StartLocation = GetOwner()->GetActorLocation();		
	
}


// Called every frame
void UMovementBossComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//void UMovementBossComponent::MoveInSineWave(float DeltaTime)
//{
//	FVector NewLocation = StartLocation;
//	NewLocation.X += CurrentVelocity.X * DeltaTime;
//	NewLocation.Y += Amplitude * FMath::Sin(Frequency * GetWorld()->GetTimeSeconds());
//	GetOwner()->SetActorLocation(NewLocation);
//
//}
//
//void UMovementBossComponent::MoveInCircle(float DeltaTime)
//{
//	float Time = GetWorld()->GetTimeSeconds();
//	FVector NewLocation = StartLocation;
//	NewLocation.X += Amplitude * FMath::Cos(Frequency * Time);
//	NewLocation.Y += Amplitude * FMath::Sin(Frequency * Time);
//	GetOwner()->SetActorLocation(NewLocation);
//
//}
//
//void UMovementBossComponent::MoveInSquare(float DeltaTime)
//{
//	FVector NewLocation = StartLocation;
//	NewLocation.X += CurrentVelocity.X * DeltaTime;
//	NewLocation.Y += CurrentVelocity.Y * DeltaTime;
//	GetOwner()->SetActorLocation(NewLocation);
//
//}
//
//void UMovementBossComponent::MoveInZigZag(float DeltaTime)
//{
//	FVector NewLocation = StartLocation;
//	NewLocation.X += CurrentVelocity.X * DeltaTime;
//	NewLocation.Y += CurrentVelocity.Y * DeltaTime;
//	GetOwner()->SetActorLocation(NewLocation);
//}

