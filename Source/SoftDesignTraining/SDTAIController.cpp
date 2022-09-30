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
    bool playerDetected = !obstacleDetected && DetectPlayer(SDTUtils::IsPlayerPoweredUp(GetWorld()));
    MoveForward();
}

void ASDTAIController::MoveForward() 
{
    APawn* pawn = GetPawn();

    // We change the player rotation according to its current rotation and its direction.
    FRotator rotation = direction.ToOrientationRotator() - pawn->GetActorForwardVector().ToOrientationRotator();
    pawn->AddActorWorldRotation(rotation, false, (FHitResult*)nullptr, ETeleportType::None);
    
    // We update the MaxAcceleration and MaxWalkSpeed of the characherMovementComponent.
    // If those parameters were not modifiable we could ddo this only once.
    GetCharacter()->GetCharacterMovement()->MaxAcceleration = ACCELERATION;
    GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = MAX_SPEED;

    pawn->AddMovementInput(direction, 1);
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
        FVector newdirection = FVector::CrossProduct(FVector::UpVector, outHits.Normal);
        float directionX = abs(newdirection.X) == 1 && rand() % 2 == 1 ? newdirection.X * -1 : newdirection.X; // Randomly reverse direction on X axis
        float directionY = abs(newdirection.Y) == 1 && rand() % 2 == 1 ? newdirection.Y * -1 : newdirection.Y; // Randomly reverse direction on Y axis
        direction = FVector(directionX, directionY, 0);

        // TODO : trajectoire arrondie pour éviter le mur
        // Ceci permet une rotation progressive comme voulue, mais le AI tourne toujours dans le même sens
        // Donc peut rester pris à certains endroits
        
        //direction = FVector(direction.X + newdirection.X, direction.Y + newdirection.Y, 0);
        //direction.Normalize();
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
            direction = pickupDetected ? -playerDirection : playerDirection;
            direction = FVector(direction.X, direction.Y, 0);
            return true;
        }
    }
    return false;
}