// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Vehicle.generated.h"

/**
 * 
 */
UCLASS()
class DELIVERYSIMTUTORIAL_API AVehicle : public AWheeledVehiclePawn
{
	GENERATED_BODY()
	
public:
	AVehicle();
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
	USpringArmComponent *CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
	UCameraComponent *Camera;

public:
	UFUNCTION()
	virtual void SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) override;

	UFUNCTION()
	void LookRight(const float Scale);

	UFUNCTION()
	void LookUp(const float Scale);

	UFUNCTION()
	void MoveForward(const float Scale);

	UFUNCTION()
	void LurnLeft(const float Scale);

	UFUNCTION()
	void MoveBack(const float Scale);

	UFUNCTION()
	void StartHandBrake();

	UFUNCTION()
	void StopHandBrake();
};
