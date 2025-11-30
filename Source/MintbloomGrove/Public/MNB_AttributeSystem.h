// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "MNB_AttributeSystem.generated.h"

UENUM(BlueprintType)
enum class EModOperation : uint8
{

	Add			UMETA(DisplayName = "Add"),
	Multiply	UMETA(DisplayName = "Multiply"),
	Add_percent UMETA(DisplayName = "Add percent"),
	Override	UMETA(DisplayName = "Override")
};

USTRUCT(BlueprintType)
struct FLevelAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	float Value = .0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	EModOperation ModType = EModOperation::Override;

};

USTRUCT(BlueprintType)
struct FLevelAttributeData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	FLevelAttribute Level1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	FLevelAttribute Level2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	FLevelAttribute Level3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	FLevelAttribute Level4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityData")
	FLevelAttribute Level5;
};

USTRUCT(BlueprintType)
struct FAttributeSystem : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	FGameplayTag ItemTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	TMap<FGameplayTag, FLevelAttributeData> Levels;
};
