// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupBase.h"
#include "Components/SphereComponent.h"

// Sets default values
APickupBase::APickupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
	CollisionArea = CreateDefaultSubobject<USphereComponent>(FName("CollisionArea"));
	CollisionArea->SetSphereRadius(500.0f);
	RootComponent = CollisionArea;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshComponent"));
	MeshComponent->SetSimulatePhysics(false);
	MeshComponent->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();
	CollisionArea->SetGenerateOverlapEvents(true);//bGenerateOverlapEvents已封装为私有变量
	CollisionArea->OnComponentBeginOverlap.AddDynamic(this,&APickupBase::OnOverlap);
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//与道具发生碰撞产生的效果
void APickupBase::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) {
	UseItem(OtherActor);
}

void APickupBase::UseItem(AActor* User) {
	//UE_LOG(LogTemp, Warning, TEXT("father type conducted"));
	CollisionArea->SetGenerateOverlapEvents(false);
	this->SetActorHiddenInGame(true);
}