// Fill out your copyright notice in the Description page of Project Settings.


#include "VRPawn.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "HandControllerBase.h"

// Sets default values
AVRPawn::AVRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	SetRootComponent(Root);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));	
	Camera->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AVRPawn::BeginPlay()
{
	Super::BeginPlay();

	if (RightHandControllerClass)
	{
		RightHandController = GetWorld()->SpawnActor<AHandControllerBase>(RightHandControllerClass);
		RightHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		RightHandController->SetOwner(this);
		RightHandController->SetTrackingSource(EControllerHand::Right);
	}
	if (LeftHandControllerClass)
	{
		LeftHandController = GetWorld()->SpawnActor<AHandControllerBase>(LeftHandControllerClass);
		LeftHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		LeftHandController->SetOwner(this);
		LeftHandController->SetTrackingSource(EControllerHand::Left);
	}	
}

// Called every frame
void AVRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

