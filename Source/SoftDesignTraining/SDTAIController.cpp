// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "SoftDesignTraining.h"
#include "SoftDesignTrainingCharacter.h"
#include "SDTUtils.h"

void ASDTAIController::Tick(float deltaTime)
{
    bool obstacleDetected = DetectWall();
    obstacleDetected = obstacleDetected || DetectDeathFloor();
    bool pickupDetected = !obstacleDetected && DetectPickup();
    bool playerDetected = !obstacleDetected && DetectPlayer(pickupDetected);
    MoveForward(deltaTime);
}

bool ASDTAIController::MoveForward(float deltaTime) 
{
    speed += (ACCELERATION * deltaTime);
    if (speed >= MAX_SPEED) speed = MAX_SPEED;

    APawn* pawn = GetPawn();
    FRotator rotation = direction.ToOrientationRotator() - pawn->GetActorForwardVector().ToOrientationRotator();

    pawn->AddActorWorldRotation(rotation, false, (FHitResult*)nullptr, ETeleportType::None);
    pawn->AddMovementInput(direction, speed);
    return false;
}

bool ASDTAIController::DetectWall() 
{
    FHitResult outHits;
    FCollisionObjectQueryParams objectQueryParams;
    objectQueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
    queryParams.bReturnPhysicalMaterial = true;

    APawn* pawn = GetPawn();
    FVector forward = pawn->GetActorForwardVector() * COLLISION_DETECTION_DISTANCE;
    FVector rayStart = pawn->GetActorLocation() * FVector(1, 1, 0) + FVector(0, 0, 254 /*Walls are at 254 on Z axis*/);
    FVector rayEnd = rayStart + forward;
    
    bool wallDetected = GetWorld()->LineTraceSingleByObjectType(outHits, rayStart, rayEnd, objectQueryParams, queryParams);
    if (wallDetected) 
    {
        direction = FVector::CrossProduct(FVector::UpVector, outHits.Normal);
        float directionX = abs(direction.X) == 1 && rand() % 2 == 1 ? direction.X * -1 : direction.X; // Randomly reverse direction on X axis
        float directionY = abs(direction.Y) == 1 && rand() % 2 == 1 ? direction.Y * -1 : direction.Y; // Randomly reverse direction on Y axis
        direction = FVector(directionX, directionY, 0);
        return true;
    }
    return false;
}

bool ASDTAIController::DetectDeathFloor() 
{
    FHitResult outHits;
    FCollisionObjectQueryParams objectQueryParams;
    objectQueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    objectQueryParams.AddObjectTypesToQuery(ECC_GameTraceChannel3);
    FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
    queryParams.bReturnPhysicalMaterial = true;

    APawn* pawn = GetPawn();
    FVector forward = pawn->GetActorForwardVector() * COLLISION_DETECTION_DISTANCE;
    FVector rayStart = pawn->GetActorLocation() * FVector(1, 1, 0) + FVector(0, 0, 130 /*Death floors are at 130 on Z axis*/);
    FVector rayEnd = FVector(rayStart.X + forward.X, rayStart.Y + forward.Y, 130);

    bool deathFloorDetected = GetWorld()->LineTraceSingleByObjectType(outHits, rayStart, rayEnd, objectQueryParams, queryParams);
    if (deathFloorDetected && outHits.GetComponent()->GetCollisionObjectType() == COLLISION_DEATH_OBJECT) 
    {
        direction = FVector::CrossProduct(FVector::UpVector, outHits.Normal);
        float directionX = abs(direction.X) == 1 && rand() % 2 == 1 ? direction.X * -1 : direction.X; // Randomly reverse direction on X axis
        float directionY = abs(direction.Y) == 1 && rand() % 2 == 1 ? direction.Y * -1 : direction.Y; // Randomly reverse direction on Y axis
        direction = FVector(directionX, directionY, 0);
        return true;
    }
    return false;
}

bool ASDTAIController::DetectPickup() 
{
    TArray<FHitResult> outHits;
    FCollisionObjectQueryParams objectQueryParams;
    objectQueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    objectQueryParams.AddObjectTypesToQuery(ECC_GameTraceChannel3);
    objectQueryParams.AddObjectTypesToQuery(ECC_GameTraceChannel5);
    FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
    queryParams.bReturnPhysicalMaterial = true;
    
    APawn* pawn = GetPawn();
    FVector forward = pawn->GetActorForwardVector() * COLLISION_DETECTION_DISTANCE;
    FVector rayStart = pawn->GetActorLocation() * FVector(1, 1, 0) + FVector(0, 0, 250 /*Collectibles are at 250 on Z axis*/) + forward;
    FVector rayEnd = FVector(rayStart.X + forward.X, rayStart.Y + forward.Y, 250);

    bool hitDetected = GetWorld()->SweepMultiByObjectType(outHits, rayStart, rayEnd, FQuat::Identity, objectQueryParams, FCollisionShape::MakeSphere(COLLISION_DETECTION_DISTANCE), queryParams);
    if (hitDetected) 
    {
        for (FHitResult outHit : outHits)
        {
            if (outHit.GetComponent()->GetCollisionObjectType() != COLLISION_COLLECTIBLE)
                continue;

            direction = outHit.GetActor()->GetActorLocation() - pawn->GetActorLocation();
            direction = FVector(direction.X, direction.Y, 0);
            return true;
        }
    }
    return false;
}

bool ASDTAIController::DetectPlayer(bool pickupDetected) 
{
    TArray<FHitResult> outHits;
    FCollisionObjectQueryParams objectQueryParams;
    objectQueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    objectQueryParams.AddObjectTypesToQuery(ECC_GameTraceChannel3);
    objectQueryParams.AddObjectTypesToQuery(ECC_GameTraceChannel4);
    FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
    queryParams.bReturnPhysicalMaterial = true;

    APawn* pawn = GetPawn();
    FVector forward = pawn->GetActorForwardVector() * COLLISION_DETECTION_DISTANCE;
    FVector rayStart = pawn->GetActorLocation() * FVector(1, 1, 0);
    FVector rayEnd = FVector(rayStart.X + forward.X, rayStart.Y + forward.Y, 0);

    bool hitDetected = GetWorld()->SweepMultiByObjectType(outHits, rayStart, rayEnd, FQuat::Identity, objectQueryParams, FCollisionShape::MakeSphere(COLLISION_DETECTION_DISTANCE), queryParams);
    if (hitDetected)
    {
        for (FHitResult outHit : outHits)
        {
            if (outHit.GetComponent()->GetCollisionObjectType() != COLLISION_PLAYER)
                continue;

            FVector playerDirection = outHit.GetActor()->GetActorLocation() - pawn->GetActorLocation();
            direction = pickupDetected ? direction * playerDirection * -1 : playerDirection;
            direction = FVector(direction.X, direction.Y, 0);
            return true;
        }
    }
    return false;
}