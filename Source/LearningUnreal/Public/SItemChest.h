// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "SItemChest.generated.h"

UCLASS()
class LEARNINGUNREAL_API ASItemChest : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ASItemChest();
	
	void Interact_Implementation(APawn* instigatorPawn);

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* baseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* lidMesh;

	UPROPERTY(EditAnywhere)
	float lidRotation = 110;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
