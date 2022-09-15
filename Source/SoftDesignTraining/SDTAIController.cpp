// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "SoftDesignTraining.h"

void ASDTAIController::Tick(float deltaTime)
{
    FVector direction = GetPawn()->GetActorForwardVector();
    MoveTowards(direction, 75, 500, deltaTime);

}

bool ASDTAIController::MoveTowards(FVector direction, float acceleration, float maxSpeed, float deltaTime) {
    speed += (acceleration * deltaTime);
    if (speed >= maxSpeed) speed = maxSpeed;
    FVector disp = speed * deltaTime * direction.GetSafeNormal();
    GetPawn()->SetActorLocation(GetPawn()->GetActorLocation() + disp, true);
    GetPawn()->SetActorRotation(disp.ToOrientationQuat());
    return false;
}
