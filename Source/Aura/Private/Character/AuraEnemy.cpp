// Copyright IVs


#include "Character/AuraEnemy.h"

void AAuraEnemy::HighlightActor()
{
	IsHighlighted = true;
	UE_LOG(LogTemp, Warning, TEXT("Is Hilighted"));
}

void AAuraEnemy::UnHighlightActor()
{
	IsHighlighted = false;
	UE_LOG(LogTemp, Warning, TEXT("Is not Hilighted"));
}
