// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "MNB_AttributeSystem.h"
#include "DTStruct.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FIconRow : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText ToolTip;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FGameplayTag, FLevelAttributeData> Effect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UTexture2D* IconTexture;
};
