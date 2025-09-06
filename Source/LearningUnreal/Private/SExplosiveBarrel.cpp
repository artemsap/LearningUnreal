// Fill out your copyright notice in the Description page of Project Settings.

#include "SExplosiveBarrel.h"

// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>( FName( "staticMeshComp" ) );
	staticMeshComp->SetSimulatePhysics(true);
	staticMeshComp->SetCollisionProfileName("PhysicsActor", false);
	RootComponent = staticMeshComp;

	radialForceComp = CreateDefaultSubobject<URadialForceComponent>( FName( "radialForceComp" ) );
	radialForceComp->SetupAttachment(staticMeshComp);
	radialForceComp->ForceStrength = 2000.0f;
	radialForceComp->Radius = 1000.0f;
	radialForceComp->ImpulseStrength = 2000.0f;
	radialForceComp->bImpulseVelChange = true;
}

void ASExplosiveBarrel::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	staticMeshComp->OnComponentHit.AddDynamic(this, &ASExplosiveBarrel::OnActorHit);
}

void ASExplosiveBarrel::OnActorHit(UPrimitiveComponent* hitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	radialForceComp->FireImpulse();
}
