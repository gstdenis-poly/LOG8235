// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "SoftDesignTraining.h"
#include "SoftDesignTrainingCharacter.h"

void ASDTAIController::Tick(float deltaTime)
{
    direction = GetPawn()->GetActorForwardVector();

    DetectWall();
    MoveForward(deltaTime);
}

bool ASDTAIController::MoveForward(float deltaTime) {
    speed += (ACCELERATION * deltaTime);
    if (speed >= MAX_SPEED) speed = MAX_SPEED;
    FVector disp = speed * deltaTime * direction.GetSafeNormal();
    GetPawn()->AddMovementInput(direction, speed);
    GetPawn()->SetActorRotation(disp.ToOrientationQuat());
    return false;
}

void ASDTAIController::DetectWall() {
    FHitResult outHits;
    FCollisionObjectQueryParams objectQueryParams;
    objectQueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
    queryParams.bReturnPhysicalMaterial = true;

    FVector forward = direction * OBSTACLE_DETECTION_DISTANCE;

    FVector rayEnd = FVector(GetPawn()->GetActorLocation().X + forward.X, GetPawn()->GetActorLocation().Y + forward.Y, GetPawn()->GetActorLocation().Z + forward.Z);
    bool wallDetected = GetWorld()->LineTraceSingleByObjectType(outHits, GetPawn()->GetActorLocation(), rayEnd, objectQueryParams, queryParams);

    if (wallDetected) direction = FVector::CrossProduct(FVector::UpVector, FVector(outHits.Normal));
}

void ASDTAIController::DetectDeathFloor() {

}