// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "SDTCollectible.generated.h"


UCLASS()
class SOFTDESIGNTRAINING_API ASDTCollectible : public AStaticMeshActor
{
	GENERATED_BODY()
public:
    ASDTCollectible();

    void Collect();
    void OnCooldownDone();
    bool IsOnCooldown();

    /// <summary>
    /// move the collectible towards the current direction
    /// </summary>
    void MoveForward(float deltaTime);

    /// <summary>
    /// Detect a possible collision with wall, change the collectible direction to avoid it.
    /// </summary>
    /// <returns>True if a wall is detected</returns>
    bool DetectWall();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
    float m_CollectCooldownDuration = 10.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        bool isMoveable = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        // Acceleration of the colletible, by default 250cm.s^2
        float ACCELERATION = 250.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        // Max speed of the collectible, by default 500cm.s
        float MAX_SPEED = 500.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        // Distance at which the collectible detects a collision, by default 100cm
        float COLLISION_DETECTION_DISTANCE = 100.f;

    virtual void Tick(float deltaTime) override;
    virtual void BeginPlay() override;

    FVector initialPosition;

protected:
    FTimerHandle m_CollectCooldownTimer;

private:
    float speed = 0; // Initial speed of collectible
    FVector direction = FVector(0, 1, 0); // Initial direction of collectible
};
