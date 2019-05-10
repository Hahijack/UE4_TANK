// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupBase.h"
#include "PickupHealth.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API APickupHealth : public APickupBase
{
	GENERATED_BODY()
	
private:
	float HealthToAdd = 30.0f;

public:
	virtual void UseItem(AActor* User) override;//重写父类方法


};
