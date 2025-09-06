// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h" 
#include "PhysicsEngine/RadialForceComponent.h"
#include "SExplosiveBarrel.generated.h"

UCLASS(Abstract)
class LEARNINGUNREAL_API ASExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASExplosiveBarrel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* staticMeshComp;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	URadialForceComponent* radialForceComp;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
