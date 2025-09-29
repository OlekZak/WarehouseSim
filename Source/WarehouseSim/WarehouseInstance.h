// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "WarehouseInstance.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FUpgradeData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString UpgradeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float UpgradePrice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bUpgradePurchased;

	FUpgradeData()
		: UpgradeName(""), UpgradePrice(0.0f), bUpgradePurchased(false)
	{}
};


UCLASS()
class WAREHOUSESIM_API UWarehouseInstance : public UGameInstance
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerData")
		float PlayerMoney = 0.0f;

	UPROPERTY(EditAnywhere, blueprintReadWrite, Category = "JobData")
		int NumberOfJobsCompleted = 0;

	
	UPROPERTY(EditAnywhere, blueprintReadWrite, Category = "PlayerData")
		TMap<FString, FUpgradeData> UpgradeData;
		
};

