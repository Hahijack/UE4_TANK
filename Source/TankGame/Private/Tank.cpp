// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	float DamagePoint = DamageAmount;
	float DamageToApply = FMath::Clamp<float>(DamagePoint, 0.0f, CurrentHp);
	CurrentHp -= DamageToApply;
	if (CurrentHp <= 0) {
		//坦克死亡
		//UE_LOG(LogTemp, Warning, TEXT("Tank dead,Tank Name:%s"), *GetName());
		OnDeath.Broadcast();
		if (IsPlayerControlled()) {

		}
		else {
			Destroy();
		}
	}
	return DamageToApply;
}

float ATank::GetHealthPercentage()
{
	return float(CurrentHp / MaxHp);
}

void ATank::AddTankHealth(float HpToAdd)
{
	CurrentHp = FMath::Clamp<int32>(CurrentHp + HpToAdd, 0, MaxHp);
}

void ATank::AddTankPower(float PowerToAdd)
{
	PowerAdd = FMath::Clamp<int32>(PowerAdd+PowerToAdd, 0, 50.0f);//最大伤害不高于50
}

float ATank::GetPowerAdd()
{
	return PowerAdd;
}

