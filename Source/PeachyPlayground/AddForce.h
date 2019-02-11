// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AddForce.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PEACHYPLAYGROUND_API UAddForce : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAddForce();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddDatForce();

private:
	// vector that we add force in. Defined in inspector
	UPROPERTY(EditAnywhere)
		FVector ForceDirection;

	// how much we multiply our force by.
	UPROPERTY(EditAnywhere)
		float ForceMultiplier;

	// use impulse?
	UPROPERTY(EditAnywhere)
		bool UseImpulse;

	// the primitive component of this actor, we gonna add force to it like a rigidbody i guess.
	UPrimitiveComponent* ThisPrimitiveComponent;
};
