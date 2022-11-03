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
        GEngine->AddOnScreenDebugMessage(200, 1.f, FColor::Red, TEXT("Jump"));

        if (!controller->InAir) {
            m_JumpProgressRatio = 0;
            controller->InAir = true;
            currentStart = segmentStart.Location;
            currentEnd = points[MoveSegmentStartIndex + 1].Location;

        }

          


        //const FNavPathPoint& segmentEnd = points[MoveSegmentStartIndex + 1];
        const FVector toTarget = currentEnd - currentStart;
        GEngine->AddOnScreenDebugMessage(23, 1.f, FColor::Cyan, FString::SanitizeFloat(currentStart.X)+ FString(" ") + FString::SanitizeFloat(currentEnd.X));

        //valeur 10 totalement arbitraire trouvée par essais-erreurs avec le code pour que le saut fonctionne en tout temps
        //Le résultat est horrible, car téléportation du AI pas fluide
        //TODO : fix
        m_JumpProgressRatio +=  5*DeltaTime; 
        GEngine->AddOnScreenDebugMessage(20, 1.f, FColor::Red, FString::SanitizeFloat(m_JumpProgressRatio));
        float curvePosition = Cast<ASDTAIController>(GetOwner())->JumpCurve->GetFloatValue(m_JumpProgressRatio);

        //Move actor to a new position while jumping along the curve
        float nextX = currentStart.X + m_JumpProgressRatio * toTarget.X;
        float nextY = currentStart.Y + m_JumpProgressRatio * toTarget.Y;
        float nextZ = currentStart.Z + controller->JumpApexHeight * curvePosition + 200;
        GEngine->AddOnScreenDebugMessage(21, 1.f, FColor::Blue, FString::SanitizeFloat(nextX));
        GEngine->AddOnScreenDebugMessage(23, 1.f, FColor::Yellow, FString::SanitizeFloat(nextX) + FString(" ") + FString::SanitizeFloat(nextY) + FString(" ") + FString::SanitizeFloat(nextZ));



        DrawDebugSphere(GetWorld(), FVector(nextX,nextY,nextZ), 20, 32, FColor::Cyan);

        controller->GetPawn()->SetActorLocation(FVector(nextX,nextY,nextZ));

        if (m_JumpProgressRatio > 1) {
            controller->GetPawn()->SetActorLocation(currentEnd);
        }
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(200, 1.f, FColor::Red, TEXT("no Jump"));
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
        controller->AtJumpSegment = true;
       
    }
    else
    {
        //Handle normal segments
        Cast<UCharacterMovementComponent>(MovementComp)->SetMovementMode(MOVE_Walking);
        controller->AtJumpSegment = false;
    }
}

