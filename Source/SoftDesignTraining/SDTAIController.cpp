// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "SoftDesignTraining.h"
#include "SoftDesignTrainingCharacter.h"
#include "SDTUtils.h"

void ASDTAIController::Tick(float deltaTime)
{
    // We update the MaxAcceleration and MaxWalkSpeed of the characherMovementComponent.
    // If those parameters were not modifiable we could do this only once.
    GetCharacter()->GetCharacterMovement()->MaxAcceleration = ACCELERATION;
    GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = MAX_SPEED;

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
    pawn->AddMovementInput(direction, 1);
}

bool ASDTAIController::DetectWall() 
{
    //Raycast initialization
    FHitResult outHits;
    FCollisionObjectQueryParams objectQueryParams;
    objectQueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
    queryParams.bReturnPhysicalMaterial = true;

    //Compute the raycast vector
    APawn* pawn = GetPawn();
    FVector forward = pawn->GetActorForwardVector() * COLLISION_DETECTION_DISTANCE;
    FVector rayStart = pawn->GetActorLocation() * FVector(1, 1, 0) + FVector(0, 0, 254 /*Walls are at 254 on Z axis*/);
    FVector rayEnd = rayStart + forward;
    
    bool wallDetected = GetWorld()->LineTraceSingleByObjectType(outHits, rayStart, rayEnd, objectQueryParams, queryParams);

    if (wallDetected) avoidObstacle(outHits);
    return wallDetected;
}

bool ASDTAIController::DetectDeathFloor() 
{
    //Raycast initialization
    FHitResult outHits;
    FCollisionObjectQueryParams objectQueryParams;
    objectQueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    objectQueryParams.AddObjectTypesToQuery(ECC_GameTraceChannel3);
    FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
    queryParams.bReturnPhysicalMaterial = true;

    //Compute the raycast vector
    APawn* pawn = GetPawn();
    FVector forward = pawn->GetActorForwardVector() * COLLISION_DETECTION_DISTANCE;
    FVector rayStart = pawn->GetActorLocation() * FVector(1, 1, 0) + FVector(0, 0, 130 /*Death floors are at 130 on Z axis*/);
    FVector rayEnd = FVector(rayStart.X + forward.X, rayStart.Y + forward.Y, 130);

    bool deathFloorDetected = GetWorld()->LineTraceSingleByObjectType(outHits, rayStart, rayEnd, objectQueryParams, queryParams);
    
    if (deathFloorDetected && outHits.GetComponent()->GetCollisionObjectType() == COLLISION_DEATH_OBJECT) 
        avoidObstacle(outHits);

    return deathFloorDetected;
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
    //Raycast initialization
    TArray<FHitResult> outHits;
    FCollisionObjectQueryParams objectQueryParams;
    objectQueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    objectQueryParams.AddObjectTypesToQuery(ECC_GameTraceChannel3);
    objectQueryParams.AddObjectTypesToQuery(ECC_GameTraceChannel4);
    FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
    queryParams.bReturnPhysicalMaterial = true;

    //Compute the raycast vector
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

            //Sets the AI direction to either chase or run away from the player
            FVector playerDirection = outHit.GetActor()->GetActorLocation() - pawn->GetActorLocation();
            direction = pickupDetected ? -playerDirection : playerDirection;
            direction = FVector(direction.X, direction.Y, 0);
            return true;
        }
    }
    return false;
}

void ASDTAIController::avoidObstacle(FHitResult outHits) 
{
    if (detectedObstacle == nullptr) detectedObstacle = outHits.GetComponent();
    else if (detectedObstacle != outHits.GetComponent()) {
        detectedObstacle = outHits.GetComponent();
        rotationSide = rand() % 2 == 1 ? 1 : -1; //randomly select which side to rotate, to prevent the AI from getting stuck
    }

    //Sets direction to the median vector of the current direction and the obstacle's normal
    //Allows to gradually redirect the AI to a new direction to avoid the obstacle
    FVector newdirection = FVector::CrossProduct(FVector::UpVector, outHits.Normal);
    direction = FVector(direction.X + (newdirection.X * rotationSide), direction.Y + (newdirection.Y * rotationSide), 0);
    direction.Normalize();

    //Slows the AI while approaching an obstacle
    GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = GetCharacter()->GetCharacterMovement()->MaxWalkSpeed / 3;
}