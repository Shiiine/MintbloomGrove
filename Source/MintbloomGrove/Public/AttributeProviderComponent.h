// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MNB_AttributeSystem.h"
#include "AttributeProviderComponent.generated.h"

USTRUCT(BlueprintType)
struct FItemEffect
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	FGameplayTag Effect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	FLevelAttribute EffectValue;

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MINTBLOOMGROVE_API UAttributeProviderComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Source")
	FGameplayTag AttributeSetTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data")
	UDataTable* AttributeDataTable = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data")
	UDataTable* EffectDataTable = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Runtime")
	mutable int CurrentGrade = 1;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	int32 GetCurrentGrade() const { return CurrentGrade; }

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetCurrentGrade(int32 NewGrade) { CurrentGrade = FMath::Clamp(NewGrade, 1, 5); }

	UFUNCTION(BlueprintCallable, Category = "Attributes", meta = (BlueprintPure, AutoCreateRefTerm = "AttributeTag", CompactNodeTitle = "Value"))
	float GetAttributeValue(UPARAM(meta = (Categories = "Attribute")) const FGameplayTag& AttributeTag) const;

	UFUNCTION(BlueprintCallable, Category = "Attributes", meta = (BlueprintPure, AutoCreateRefTerm = "AttributeTag", CompactNodeTitle = "Value"))
	TMap<FGameplayTag, FLevelAttributeData> GetItemEffect(UPARAM(meta = (Categories = "Attribute")) const FString ItemID) const;

private:
	mutable TOptional<TMap<FGameplayTag, FLevelAttributeData>> CachedLevels;

	const TMap<FGameplayTag, FLevelAttributeData>* GetCachedLevels() const;

};
