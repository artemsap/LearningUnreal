// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "SMagicProjecttile.generated.h"

UCLASS()
class LEARNINGUNREAL_API ASMagicProjecttile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASMagicProjecttile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* sphereComp;
	
	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* movementComp;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* effectComp;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
