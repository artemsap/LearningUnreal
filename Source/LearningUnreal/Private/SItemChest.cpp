// Fill out your copyright notice in the Description page of Project Settings.


#include "SItemChest.h"

// Sets default values
ASItemChest::ASItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>( FName( "BaseMesh" ) );
	RootComponent = baseMesh;
	
	lidMesh = CreateDefaultSubobject<UStaticMeshComponent>( FName( "LidMesh" ) );
	lidMesh->SetupAttachment(baseMesh);
}

void ASItemChest::Interact_Implementation(APawn* instigatorPawn)
{
	lidMesh->SetRelativeRotation(FRotator(lidRotation, 0, 0));
}

// Called when the game starts or when spawned
void ASItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

