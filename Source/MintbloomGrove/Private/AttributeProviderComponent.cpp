// Fill out your copyright notice in the Description page of Project Settings.

#include "AttributeProviderComponent.h"
#include "Engine/DataTable.h"
#include "MNB_AttributeSystem.h" 
#include "DTStruct.h"

const TMap<FGameplayTag, FLevelAttributeData>* UAttributeProviderComponent::GetCachedLevels() const
{
    if (CachedLevels.IsSet())
    {
        return &CachedLevels.GetValue();
    }

    if (!AttributeDataTable || !AttributeSetTag.IsValid())
    {
        return nullptr;
    }


    FName RowName = AttributeSetTag.GetTagName();
    const FAttributeSystem* Row = AttributeDataTable->FindRow<FAttributeSystem>(RowName, TEXT("AttributeProvider"));
    if (!Row)
    {
        return nullptr;
    }

    CachedLevels = Row->Levels;
    return &CachedLevels.GetValue();
}

float UAttributeProviderComponent::GetAttributeValue(const FGameplayTag& AttributeTag) const
{
    if (CurrentGrade < 1 || CurrentGrade > 5) return 0.0f;

    const auto* Levels = GetCachedLevels();
    if (!Levels) return 0.0f;

    const FLevelAttributeData* Data = Levels->Find(AttributeTag);
    if (!Data) return 0.0f;

    return Data->GetLevelAttribute(CurrentGrade).Value;
}


TMap<FGameplayTag, FLevelAttributeData> UAttributeProviderComponent::GetItemEffect(const FString ItemID) const
{
    TMap<FGameplayTag, FLevelAttributeData> ReturnMap;
    if (!AttributeDataTable)
    {
        return ReturnMap;
    }
    const FIconRow* Row = EffectDataTable->FindRow<FIconRow>(FName(ItemID), TEXT("AttributeProvider"));
    if (!Row)
    {
        return ReturnMap;
    }

    ReturnMap = Row->Effect;
    return ReturnMap;
}
