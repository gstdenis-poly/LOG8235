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
    // main loop called every tick
    virtual void Tick(float deltaTime) override;

    /// <summary>
    /// move the character towards the current direction
    /// </summary>
    void MoveForward();

    /// <summary>
    /// Detect a possible collision with wall, change the character direction to avoid it.
    /// </summary>
    /// <returns>True if a wall is detected</returns>
    bool DetectWall();

    /// <summary>
    /// Detect a possible collision with death floor, change the character direction to avoid it.
    /// </summary>
    /// <returns>True if a death floor is detected</returns>
    bool DetectDeathFloor();

    /// <summary>
    /// Detect if the player is near, runs from it if powered up, towards him if not.
    /// </summary>
    /// <returns>True if player is near</returns>
    bool DetectPlayer(bool pickupDetected);

    /// <summary>
    /// Detect if the pickup is near, runs towards it.
    /// </summary>
    /// <returns>True if pickup is near</returns>
    bool DetectPickup();

    /// <summary>
    /// Redirects the AI to avoid the obstacle detected (Wall or DeathFloor).
    /// </summary>
    void avoidObstacle(FHitResult outHits);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (ClampMin = 1, ClampMax = 250))
        // Acceleration of the AI character, by default 1m.s^-2, can be set between 1 and 10
        float ACCELERATION = 200.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (ClampMin = 1, ClampMax = 600))
        // Max speed of the AI character, by default 1m.s^-1, can be set between 1 and 10
        float MAX_SPEED = 500.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (ClampMin = 100, ClampMax = 1000))
        // Distance at which the AI character detects a collision, by default 200cm, can be set between 10 and 1000
        float COLLISION_DETECTION_DISTANCE = 200.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
        float speed = 0.f;

private:
    UPrimitiveComponent* detectedObstacle = nullptr; // Keeps track of the current obstacle being rayCast.
    float rotationSide = 1; // Keeps track of the rotation side for the AI
    FVector direction = FVector(1, 0, 0); // AI's direction
};
