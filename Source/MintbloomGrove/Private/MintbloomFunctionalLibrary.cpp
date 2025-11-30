// Fill out your copyright notice in the Description page of Project Settings.


#include "MintbloomFunctionalLibrary.h"

bool UMintbloomFunctionalLibrary::GetPlayInEditor()
{
#if WITH_EDITOR
    return true;
#else
    return false;
#endif
}
