// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupHealth.h"

#include "Tank.h"
void APickupHealth::UseItem(AActor* User) {
	FString name = User->GetName();
	name = name.Mid(0, 7);
	UE_LOG(LogTemp, Warning, TEXT("Name is: %s"), *name);
	if (name == "BP_Tank")
	{
		Super::UseItem(User);
		/*FString name = User->GetName;
		UE_LOG(LogTemp, Warning, TEXT("Name is: %s"), *name);*/
		ATank* UserTank = Cast<ATank>(User);
		UserTank->AddTankHealth(HealthToAdd);
	}
	else
	{
		return;
	}
}