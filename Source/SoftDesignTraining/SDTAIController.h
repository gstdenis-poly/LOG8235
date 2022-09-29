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
    bool DetectPlayer();
    bool DetectPickup();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float ACCELERATION = 0.2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float MAX_SPEED = 0.6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float COLLISION_DETECTION_DISTANCE = 200;

private:
    float speed = 0;
    FVector direction = FVector(1, 0, 0);
};
