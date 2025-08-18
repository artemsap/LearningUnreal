// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrel.h"

// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>( FName( "staticMeshComp" ) );
	staticMeshComp->SetNotifyRigidBodyCollision(true); // Включаем уведомления
	staticMeshComp->SetCollisionResponseToChannel(
		ECC_WorldStatic, 
		ECR_Ignore            // Игнорируем события Hit (альтернативный вариант)
	);
	
	RootComponent = staticMeshComp;

	radialForceComp = CreateDefaultSubobject<URadialForceComponent>( FName( "radialForceComp" ) );
	radialForceComp->SetupAttachment(staticMeshComp);
	radialForceComp->ForceStrength = 1000.0f;
	radialForceComp->Radius = 500.0f;
}

// Called when the game starts or when spawned
void ASExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

