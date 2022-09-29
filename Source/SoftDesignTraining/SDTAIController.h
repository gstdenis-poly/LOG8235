// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SoftDesignTrainingCharacter.h"
#include "SDTUtils.h"
#include "SDTAIController.generated.h"

/**
 *
 */
UCLASS(ClassGroup = AI, config = Game)
class SOFTDESIGNTRAINING_API ASDTAIController : public AAIController
{
    GENERATED_BODY()
public:
    virtual void Tick(float deltaTime) override;
    bool MoveForward(float deltaTime);
    bool DetectWall();
    bool DetectDeathFloor();
    bool DetectPlayer(bool pickupDetected);
    bool DetectPickup();

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (ClampMin = 1, ClampMax = 250))
        // Acceleration of the AI character, by default 1m.s^-2, can be set between 1 and 10
        float ACCELERATION = 200;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (ClampMin = 1, ClampMax = 600))
        // Max speed of the AI character, by default 1m.s^-1, can be set between 1 and 10
        float MAX_SPEED = 500;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (ClampMin = 100, ClampMax = 1000))
        // Distance at which the AI character detects a collision, by default 200cm, can be set between 10 and 1000
        float COLLISION_DETECTION_DISTANCE = 200;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
        float speed = 0;
private:

    FVector direction = FVector(1, 0, 0);
};
