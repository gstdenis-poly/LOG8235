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

    if (SDTUtils::HasJumpFlag(segmentStart))
    {
        const FNavPathPoint& segmentEnd = points[MoveSegmentStartIndex + 1];
        const FVector toTarget = segmentEnd.Location - segmentStart.Location;

        m_JumpProgressRatio += DeltaTime;
        float curvePosition = Cast<ASDTAIController>(GetOwner())->JumpCurve->GetFloatValue(m_JumpProgressRatio);

        //Move actor to a new position while jumping along the curve
        float nextX = startingJumpPoint.X + m_JumpProgressRatio * toTarget.X;
        float nextY = startingJumpPoint.Y + m_JumpProgressRatio * toTarget.Y;
        float nextZ = startingJumpPoint.Z + controller->JumpApexHeight * curvePosition;

        controller->GetPawn()->SetActorLocation(FVector(nextX, nextY, nextZ));
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

    if (SDTUtils::HasJumpFlag(segmentStart) && FNavMeshNodeFlags(segmentStart.Flags).IsNavLink())
    {
        //Handle starting jump
        Cast<UCharacterMovementComponent>(MovementComp)->SetMovementMode(MOVE_Flying);
        controller->AtJumpSegment = true;
        m_JumpProgressRatio = 0;
    }
    else
    {
        //Handle normal segments
        Cast<UCharacterMovementComponent>(MovementComp)->SetMovementMode(MOVE_Walking);
        controller->AtJumpSegment = false;
    }
}

