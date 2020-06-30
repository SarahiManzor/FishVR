// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HandControllerBase.generated.h"

class UMotionControllerComponent;
class UStaticMeshComponent;

UCLASS()
class FISHVR_API AHandControllerBase : public AActor
{
	GENERATED_BODY()
	
// ----------Base Functions----------
public:
	AHandControllerBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

// ----------Variables----------
public:
protected:
private:
	// Components
	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ControllerMesh;

// ----------Custom Functions----------
public:
	void SetTrackingSource(EControllerHand Hand);

};
