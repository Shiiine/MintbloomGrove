// Fill out your copyright notice in the Description page of Project Settings.


#include "MintbloomFunctionalLibrary.h"
#include "DTStruct.h"

bool UMintbloomFunctionalLibrary::GetPlayInEditor()
{
#if WITH_EDITOR
    return true;
#else
    return false;
#endif
}

FIconRow UMintbloomFunctionalLibrary::GetIconRow(FString IconName)
{
    if (IconName.IsEmpty()) return FIconRow();


    static UDataTable* IconTable = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/_Mintbloom/DT/ICOItem_DT.ICOItem_DT'"));
    if (!IconTable) return FIconRow();

    FName RowName = FName(IconName);
    const FIconRow* Row = IconTable->FindRow<FIconRow>(RowName, TEXT("GetIconRow"));
    if (!Row) return FIconRow();

    return *Row;
}
