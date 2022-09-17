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
    bool MoveTowards(FVector direction, float acceleration, float maxSpeed, float deltaTime);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float ACCELERATION = 0,1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float MAX_SPEED = 1,0;

private:
    float speed = 0;
};
