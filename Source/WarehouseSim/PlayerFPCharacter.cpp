// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFPCharacter.h"

// Sets default values
APlayerFPCharacter::APlayerFPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	PlayerCamera->SetupAttachment(RootComponent);
	PlayerCamera->SetRelativeLocation(FVector(0, 0, 40));

	bJumping = false;
}

// Called when the game starts or when spawned
void APlayerFPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerFPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bJumping)
	{
		Jump();
	}

}

// Called to bind functionality to input
void APlayerFPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Forward", this, &APlayerFPCharacter::MoveForward);
	InputComponent->BindAxis("Right", this, &APlayerFPCharacter::MoveRight);
	InputComponent->BindAxis("LookRight", this, &APlayerFPCharacter::Turn);
	InputComponent->BindAxis("LookUP", this, &APlayerFPCharacter::LookUp);

	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerFPCharacter::CheckJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APlayerFPCharacter::CheckJump);
}

void APlayerFPCharacter::MoveForward(float value)
{
	if (value)
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}
void APlayerFPCharacter::MoveRight(float value)
{
	if (value)
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}
void APlayerFPCharacter::Turn(float value)
{
	if (value)
	{
		AddActorLocalRotation(FRotator(0, value, 0));
	}
}
void APlayerFPCharacter::LookUp(float value)
{
	if (value)
	{
		float temp = PlayerCamera->GetRelativeRotation().Pitch + value;

		if (temp < 65 && temp > -65)
		{
			PlayerCamera->AddLocalRotation(FRotator(value, 0, 0));
		}
	} 
}

void APlayerFPCharacter::CheckJump()
{
	if (bJumping)
	{
		bJumping = false;
	}
	else
	{
		bJumping = true;
	}
}