// Fill out your copyright notice in the Description page of Project Settings.


#include "SInteractionComponent.h"

#include "SGameplayInterface.h"

// Sets default values for this component's properties
USInteractionComponent::USInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USInteractionComponent::PrimaryInteraction()
{
	FCollisionObjectQueryParams collisionParams;
	collisionParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	auto owner = GetOwner();
	
	FVector start;
	FRotator eyesRotation;
	owner->GetActorEyesViewPoint(start,eyesRotation );
	FVector end = start + eyesRotation.Vector() * hitDistance;

	FCollisionShape collisionShape;
	collisionShape.SetSphere(30.0f);
	
	if (TArray<FHitResult> hitsResult; GetWorld()->SweepMultiByObjectType(hitsResult, start, end, FQuat::Identity, collisionParams, collisionShape))
	{
		for (const auto& hitResult : hitsResult)
		{
			if (auto hitActor = hitResult.GetActor(); hitActor && hitActor->Implements<USGameplayInterface>())
			{
				ISGameplayInterface::Execute_Interact(hitActor, Cast<APawn>(owner));
				break;
			}
			//DrawDebugSphere(GetWorld(), hitResult.ImpactPoint, 30.0f, 32, FColor::Red, false, 5);
		}
	}

	//DrawDebugLine(GetWorld(), start, end, FColor::Red, false, 5);
}

