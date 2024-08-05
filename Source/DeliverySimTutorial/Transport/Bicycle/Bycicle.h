// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeliverySimTutorial/Transport/Vehicle.h"
#include "Bycicle.generated.h"

/**
 * 
 */
UCLASS()
class DELIVERYSIMTUTORIAL_API ABycicle : public AVehicle
{
	GENERATED_BODY()
	
public:
	ABycicle();

	virtual void BeginPlay() override;
};
