// Fill out your copyright notice in the Description page of Project Settings.

#include "AddForce.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UAddForce::UAddForce()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAddForce::BeginPlay()
{
	Super::BeginPlay();

	// Get primitive component
	ThisPrimitiveComponent = GetOwner()->FindComponentByClass<UPrimitiveComponent>();
	
}


// Called every frame
void UAddForce::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AddDatForce();

}

void UAddForce::AddDatForce()
{
	if (UseImpulse)
	{
		// adds impulse force every frame, yikes!
		ThisPrimitiveComponent->AddImpulse(ForceDirection * ForceMultiplier);
	}
	else
	{
		// add regular force to primitive component
		ThisPrimitiveComponent->AddForce(ForceDirection * ForceMultiplier);
	}
}

