// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
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
    FGameplayTag Effect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UTexture2D* IconTexture;
};
