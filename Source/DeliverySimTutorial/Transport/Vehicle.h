// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
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
};
