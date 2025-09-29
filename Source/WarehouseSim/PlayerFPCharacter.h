// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraComponent.h"
#include "WarehouseSim/WarehouseInstance.h"
#include "PlayerFPCharacter.generated.h"


UCLASS()
class WAREHOUSESIM_API APlayerFPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerFPCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UpgradteData")
		TMap<FString, FUpgradeData> UpgradeData;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* PlayerCamera;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);

	void Turn(float Value);
	void LookUp(float Value);
	
	void CheckJump();
	UPROPERTY()
		bool bJumping;

	
};
