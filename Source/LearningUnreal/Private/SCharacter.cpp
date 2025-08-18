// Fill out your copyright notice in the Description page of Project Settings.

#include "SCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	springArmComp = CreateDefaultSubobject<USpringArmComponent>( FName( "SprintArmComp" ) );
	springArmComp->SetupAttachment(this->RootComponent);
	springArmComp->bUsePawnControlRotation = true;
	
	cameraComp = CreateDefaultSubobject<UCameraComponent>( FName( "CameraComp" ) );
	cameraComp->SetupAttachment(springArmComp);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	
	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);
	
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("MainAttack", IE_Pressed, this, &ASCharacter::MainAttack);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASCharacter::Jump);
}

void ASCharacter::MoveForward(float Value)
{
	auto controlRotation = GetControlRotation();
	controlRotation.Pitch = 0.0f;
	controlRotation.Roll = 0.0f;
	
	AddMovementInput(controlRotation.Vector(), Value);
}

void ASCharacter::MoveRight(float Value)
{
	auto controlRotation = GetControlRotation();
	controlRotation.Pitch = 0.0f;
	controlRotation.Roll = 0.0f;

	auto rightVector = FRotationMatrix(controlRotation).GetScaledAxis(EAxis::Y);
	
	AddMovementInput(rightVector, Value);
}

void ASCharacter::MainAttack()
{
	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	auto handLocation = GetMesh()->GetSocketLocation(FName("Muzzle_01"));
	
	GetWorld()->SpawnActor<AActor>(projectileClass, handLocation, GetControlRotation(), spawnParameters);
}

void ASCharacter::ToggleCrouch()
{
	if (CanCrouch()) // Проверка, может ли персонаж присесть
	{
		Crouch(); // Присесть
	}
	else
	{
		UnCrouch(); // Встать
	}
}
