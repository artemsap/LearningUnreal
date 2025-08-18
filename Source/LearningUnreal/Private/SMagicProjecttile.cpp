// Fill out your copyright notice in the Description page of Project Settings.


#include "SMagicProjecttile.h"

// Sets default values
ASMagicProjecttile::ASMagicProjecttile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	sphereComp = CreateDefaultSubobject<USphereComponent>( FName( "SphereComp" ) );
	sphereComp->SetCollisionProfileName("Projectile");
	
	RootComponent = sphereComp;

	effectComp = CreateDefaultSubobject<UParticleSystemComponent>(FName( "EffectComp" ) );
	effectComp->SetupAttachment(RootComponent);

	movementComp = CreateDefaultSubobject<UProjectileMovementComponent>(FName( "MovementComp" ) );
	movementComp->InitialSpeed = 1000.0f;
	movementComp->bRotationFollowsVelocity = true;
	movementComp->bInitialVelocityInLocalSpace = true;
}

// Called when the game starts or when spawned
void ASMagicProjecttile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASMagicProjecttile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

