// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "SoftDesignTraining.h"
#include "SoftDesignTrainingCharacter.h"

void ASDTAIController::Tick(float deltaTime)
{
    FVector direction = GetPawn()->GetActorForwardVector();
    MoveTowards(direction, ACCELERATION, MAX_SPEED, deltaTime);
}

bool ASDTAIController::MoveTowards(FVector direction, float acceleration, float maxSpeed, float deltaTime) {
    speed += (acceleration * deltaTime);
    if (speed >= maxSpeed) speed = maxSpeed;
    FVector disp = speed * deltaTime * direction.GetSafeNormal();
    //GetPawn()->SetActorLocation(GetPawn()->GetActorLocation() + disp, true); //Le mouvement du personnage n'est pas animé
    GetPawn()->AddMovementInput(direction, speed); //Permet d'animer le mouvement du personnage
    GetPawn()->SetActorRotation(disp.ToOrientationQuat());
    return false;
}
