// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "SoftDesignTraining.h"



bool ASDTAIController::MoveTowards(FVector2D direction, float acceleration, float maxSpeed, float deltaTime) {
	speed = speed + (acceleration *  deltaTime);
	if (speed > maxSpeed) speed = maxSpeed;
	FVector2D disp = speed * deltaTime * direction.GetSafeNormal();
	GetPawn()->SetActorLocation(GetPawn()->GetActorLocation() + FVector(disp, 0.f), true);
	GetPawn()->SetActorRotation(FVector(disp, 0.f).ToOrientationQuat());
	return false;


}

void ASDTAIController::Tick(float deltaTime)
{
	FVector2D direction = FVector2D(-1180, 400);
	MoveTowards(direction, 1, 10, deltaTime);

}




