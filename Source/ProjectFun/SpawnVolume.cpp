// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"

#include "Enemy.h"
#include "BaseGizmos/GizmoMath.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawning Box"));
	

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetSpawnPoint()
{
	const FVector Extent = SpawningBox->GetScaledBoxExtent();
	const FVector Origin = SpawningBox->GetComponentLocation();
	
	FVector Point = UKismetMathLibrary::RandomPointInBoundingBox(Origin, Extent);

	return Point;
}

void ASpawnVolume::SpawnPawn_Implementation(UClass* ToSpawn, const FVector& Location)
{
	if(ToSpawn)
	{
		UWorld* World = GetWorld();
		FActorSpawnParameters SpawnParameters;
		
		if(World)
		{
			AEnemy* EnemySpawned = World->SpawnActor<AEnemy>(ToSpawn, Location, FRotator(0.f), SpawnParameters);
		}
	}
}
