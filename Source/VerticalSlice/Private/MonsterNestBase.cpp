// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterNestBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMonsterNestBase::AMonsterNestBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// add components
	NestMesh = CreateDefaultSubobject<UStaticMeshComponent>("MonsterNestMesh");
	SetRootComponent(NestMesh);
}

// Called when the game starts or when spawned
void AMonsterNestBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMonsterNestBase::DropItems_Implementation()
{
	// make sure the DropTable array is populated
	if (DropTable.Num()>0)
	{
		// determine how many parts to drop
		int32 NumDrops = FMath::RandRange(MinNumOfDrops, MaxNumOfDrops);

		for (int i = 0; i < NumDrops; i++)
		{
			// get the item to drop
			int32 DropIndex = FMath::RandRange(0, DropTable.Num() - 1);

			ToSpawn = DropTable[DropIndex];

			SpawnDrop();
		}
	}
}

// Called every frame
void AMonsterNestBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMonsterNestBase::SpawnDrop()
{
	if (ToSpawn)
	{
		UWorld* world = GetWorld();
		if (world)
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;

			FRotator rotator;

			FVector spawnLocation = GetActorLocation();

			world->SpawnActor<ADropsBase>(ToSpawn, spawnLocation, rotator, spawnParams);
		}
	}
	//FActorSpawnParameters SpawnParams;
	//AActor* SpawnedActorRef = GetWorld()->SpawnActor<ADropsBase>()
}

void AMonsterNestBase::Destroy_Implementation()
{
}

