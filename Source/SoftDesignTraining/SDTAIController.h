// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SoftDesignTrainingCharacter.h"
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
    void AvoidWallCollision();
    void DetectWall();
    void DetectDeathFloor();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float ACCELERATION = 0.1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float MAX_SPEED = 1.0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float OBSTACLE_DETECTION_DISTANCE = 100;

private:
    float speed = 0;
    FVector direction = FVector(0, 0, 0);
};
