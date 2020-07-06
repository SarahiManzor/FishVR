// Fill out your copyright notice in the Description page of Project Settings.


#include "HandControllerBase.h"
#include "MotionControllerComponent.h" 
#include "Components/StaticMeshComponent.h"

// Sets default values
AHandControllerBase::AHandControllerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	MotionController->SetupAttachment(Root);

	ControllerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	ControllerMesh->SetupAttachment(MotionController);
}

// Called when the game starts or when spawned
void AHandControllerBase::BeginPlay()
{
	Super::BeginPlay();

	/*if (!ControllerMesh->GetStaticMesh())
	{
		MotionController->bDisplayDeviceModel = true;
	}*/
}

// Called every frame
void AHandControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHandControllerBase::SetTrackingSource(EControllerHand Hand)
{
	if (MotionController)
	{
		MotionController->SetTrackingSource(Hand);
	}
}

