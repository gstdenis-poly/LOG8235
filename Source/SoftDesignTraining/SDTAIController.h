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
    bool DetectPlayer(UWorld* uWorld);
    bool DetectPickup();
    void ChasePlayer(FVector playerPosition);
    void RunAwayFromPlayer(FVector playerPosition);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float ACCELERATION = 1.0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float MAX_SPEED = 1.0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float BLOCKING_DETECTION_DISTANCE = 100;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float OVERLAPPING_DETECTION_DISTANCE = 200;

private:
    float speed = 0;
    float rotationAngle = 15;
    FVector direction = FVector(1, 0, 0);
};
