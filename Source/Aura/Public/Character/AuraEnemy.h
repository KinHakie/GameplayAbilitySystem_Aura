// Copyright IVs

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/TargetInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public ITargetInterface
{
	GENERATED_BODY()

public:

	
	AAuraEnemy();

	//Enemy Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	// End Enemy Interface

protected:

	void BeginPlay() override;
	

	
};
