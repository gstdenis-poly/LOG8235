// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "SDTCollectible.generated.h"

/**
 * 
 */
UCLASS()
class SOFTDESIGNTRAINING_API ASDTCollectible : public AStaticMeshActor
{
	GENERATED_BODY()
public:
    ASDTCollectible();

    void Collect();
    void OnCooldownDone();
    bool IsOnCooldown();
    bool MoveForward(float deltaTime);
    bool DetectWall();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
    float m_CollectCooldownDuration = 10.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        bool isMoveable = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float ACCELERATION = 250.0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float MAX_SPEED = 500.0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float COLLISION_DETECTION_DISTANCE = 100;

    virtual void Tick(float deltaTime) override;
    virtual void BeginPlay() override;

    FVector initialPosition;

protected:
    FTimerHandle m_CollectCooldownTimer;

private:
    float speed = 0;
    FVector direction = FVector(0, 1, 0);
};
