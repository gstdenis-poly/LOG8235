// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTPathFollowingComponent.h"
#include "SoftDesignTraining.h"
#include "SDTUtils.h"
#include "SDTAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "DrawDebugHelpers.h"

USDTPathFollowingComponent::USDTPathFollowingComponent(const FObjectInitializer& ObjectInitializer)
{

}

void USDTPathFollowingComponent::FollowPathSegment(float DeltaTime)
{
    const TArray<FNavPathPoint>& points = Path->GetPathPoints();
    const FNavPathPoint& segmentStart = points[MoveSegmentStartIndex];
    const FVector startingJumpPoint = segmentStart.Location;

    ASDTAIController* controller = Cast<ASDTAIController>(GetOwner());

    if (SDTUtils::HasJumpFlag(segmentStart) || controller->InAir)
    {
        if (!controller->InAir) {
            m_JumpProgressRatio = 0;
            controller->InAir = true;
            controller->AtJumpSegment = true;
            currentStart = segmentStart.Location;
            currentEnd = points[MoveSegmentStartIndex + 1].Location;
        }

        const FVector toTarget = currentEnd - currentStart;

        m_JumpProgressRatio +=  DeltaTime; 
        float curvePosition = Cast<ASDTAIController>(GetOwner())->JumpCurve->GetFloatValue(m_JumpProgressRatio);

        //Move actor to a new position while jumping along the curve
        float nextX = currentStart.X + m_JumpProgressRatio * toTarget.X;
        float nextY = currentStart.Y + m_JumpProgressRatio * toTarget.Y;
        float nextZ = currentStart.Z + controller->JumpApexHeight * curvePosition + 50;

        controller->GetPawn()->SetActorLocation(FVector(nextX,nextY,nextZ));

        if (m_JumpProgressRatio >= 1)
        {
            GEngine->AddOnScreenDebugMessage(26, 1.f, FColor::Red, TEXT("LANDING"));
            controller->Landing = true;
            controller->AtJumpSegment = false;
            controller->InAir = false;
            m_JumpProgressRatio = 0;
        }
    }
    else
    {
        //update navigation along path
        Super::FollowPathSegment(DeltaTime);
    }
}

void USDTPathFollowingComponent::SetMoveSegment(int32 segmentStartIndex)
{
    Super::SetMoveSegment(segmentStartIndex);

    const TArray<FNavPathPoint>& points = Path->GetPathPoints();

    const FNavPathPoint& segmentStart = points[MoveSegmentStartIndex];

    ASDTAIController* controller = Cast<ASDTAIController>(GetOwner());

        if (SDTUtils::HasJumpFlag(segmentStart) && FNavMeshNodeFlags(segmentStart.Flags).IsNavLink() || controller->InAir)
        {
            //Handle starting jump
            Cast<UCharacterMovementComponent>(MovementComp)->SetMovementMode(MOVE_Flying);
        }
        else
        {
            //Handle normal segments
            Cast<UCharacterMovementComponent>(MovementComp)->SetMovementMode(MOVE_Walking);
        }
}

