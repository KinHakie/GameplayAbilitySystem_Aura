// Copyright IVs


#include "Actor/AuraEffectActor.h"

#include "Components/SphereComponent.h"
#include <AbilitySystemInterface.h>
#include <AbilitySystem/AuraAttributeSet.h>
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include <AbilitySystemBlueprintLibrary.h>



AAuraEffectActor::AAuraEffectActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
	
}


void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	
	if (TargetASC == nullptr) return;
	check(GameplayEffectClass);

	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}


