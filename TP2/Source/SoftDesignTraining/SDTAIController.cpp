// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "SoftDesignTraining.h"
#include "SDTCollectible.h"
#include "SDTFleeLocation.h"
#include "SDTPathFollowingComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "NavigationSystem.h"
//#include "UnrealMathUtility.h"
#include "SDTUtils.h"
#include "EngineUtils.h"

ASDTAIController::ASDTAIController(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer.SetDefaultSubobjectClass<USDTPathFollowingComponent>(TEXT("PathFollowingComponent")))
{
}

void ASDTAIController::GoToBestTarget(float deltaTime)
{
    //Move to target depending on current behavior
    GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = movementSpeed;
    MoveToLocation(targetPosition);
}

UNavigationPath* ASDTAIController::GetPathToClosestCollectible()
{
    //Getting the position of all the collectibles
    TArray<AActor*> collectibles = TArray<AActor*>();
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASDTCollectible::StaticClass(), collectibles);

    float currentPathLength = 1000000000000.f;
    UNavigationPath* shortestPath = nullptr;
    AActor* closestActor = collectibles[0];

    //Computing path for each collectible and finding the closest one
    for (AActor* collectible : collectibles) {
        UNavigationSystemV1* navigationSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
        UNavigationPath* collectiblePath = navigationSystem->FindPathToLocationSynchronously(GetWorld(), GetPawn()->GetActorLocation(), collectible->GetActorLocation());
        float pathLength = collectiblePath->GetPathLength();
        if (pathLength < currentPathLength && !Cast<ASDTCollectible>(collectible)->IsOnCooldown()) {
            shortestPath = collectiblePath;
            currentPathLength = pathLength;
            closestActor = collectible;
        }
    }
    targetPosition = closestActor->GetActorLocation();
    return shortestPath;
}

UNavigationPath* ASDTAIController::GetPathToActor(FVector actorPosition)
{
    UNavigationSystemV1* navigationSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
    UNavigationPath* pathToActor = navigationSystem->FindPathToLocationSynchronously(GetWorld(), GetPawn()->GetActorLocation(), actorPosition);
    targetPosition = actorPosition;
    return pathToActor;
}

UNavigationPath* ASDTAIController::GetPathToBestFleePoint(FVector actorPosition)
{
    //Getting the position of all the fleePoints
    TArray<AActor*> fleePoints = TArray<AActor*>();
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASDTFleeLocation::StaticClass(), fleePoints);

    float currentPathLength = 1000000000000.f;
    UNavigationPath* shortestPath = nullptr;
    AActor* closestActor = fleePoints[0];

    //Computing path for each fleePoint and finding the closest one that doesn't intersect the player
    for (AActor* fleePoint : fleePoints) {
        UNavigationSystemV1* navigationSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
        UNavigationPath* fleePath = navigationSystem->FindPathToLocationSynchronously(GetWorld(), GetPawn()->GetActorLocation(), fleePoint->GetActorLocation());
        float pathLength = fleePath->GetPathLength();

        FVector distanceToPlayer = actorPosition - fleePoint->GetActorLocation();
        FVector distanceToAI = GetPawn()->GetActorLocation() - fleePoint->GetActorLocation();

        if (distanceToPlayer.Size() > distanceToAI.Size() && pathLength < currentPathLength) {
            shortestPath = fleePath;
            currentPathLength = pathLength;
            closestActor = fleePoint;
        }
    }
    targetPosition = closestActor->GetActorLocation();
    return shortestPath;
}

void ASDTAIController::OnMoveToTarget()
{
    m_ReachedTarget = false;
}

void ASDTAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
    Super::OnMoveCompleted(RequestID, Result);

    m_ReachedTarget = true;
}

void ASDTAIController::ShowNavigationPath()
{
    //Show current navigation path DrawDebugLine and DrawDebugSphere
    UNavigationSystemV1* navigationSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
    UNavigationPath* path = navigationSystem->FindPathToLocationSynchronously(GetWorld(), GetPawn()->GetActorLocation(), targetPosition);

    const TArray<FVector> points = path->PathPoints;
    if (points.Num() > 0) {
        FVector startPoint = points[0];
        for (FVector point : points) {
            DrawDebugLine(GetWorld(), startPoint, point, FColor::Green);
            DrawDebugSphere(GetWorld(), point, 10.0f, 10, FColor::Red);
            startPoint = point;
        }
    }
}

void ASDTAIController::ChooseBehavior(float deltaTime)
{
    UpdatePlayerInteraction(deltaTime);
}

void ASDTAIController::UpdatePlayerInteraction(float deltaTime)
{
    //finish jump before updating AI state
    if (AtJumpSegment)
        return;

    APawn* selfPawn = GetPawn();
    if (!selfPawn)
        return;

    ACharacter* playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (!playerCharacter)
        return;

    FVector detectionStartLocation = selfPawn->GetActorLocation() + selfPawn->GetActorForwardVector() * m_DetectionCapsuleForwardStartingOffset;
    FVector detectionEndLocation = detectionStartLocation + selfPawn->GetActorForwardVector() * m_DetectionCapsuleHalfLength * 2;

    TArray<TEnumAsByte<EObjectTypeQuery>> detectionTraceObjectTypes;
    detectionTraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(COLLISION_COLLECTIBLE));
    detectionTraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(COLLISION_PLAYER));

    TArray<FHitResult> allDetectionHits;
    GetWorld()->SweepMultiByObjectType(allDetectionHits, detectionStartLocation, detectionEndLocation, FQuat::Identity, detectionTraceObjectTypes, FCollisionShape::MakeSphere(m_DetectionCapsuleRadius));

    FHitResult detectionHit;
    GetHightestPriorityDetectionHit(allDetectionHits, detectionHit);

    //Set behavior based on hit
    SetPlayerBehavior(detectionHit);

    DrawDebugCapsule(GetWorld(), detectionStartLocation + m_DetectionCapsuleHalfLength * selfPawn->GetActorForwardVector(), m_DetectionCapsuleHalfLength, m_DetectionCapsuleRadius, selfPawn->GetActorQuat() * selfPawn->GetActorUpVector().ToOrientationQuat(), FColor::Blue);
}

void ASDTAIController::GetHightestPriorityDetectionHit(const TArray<FHitResult>& hits, FHitResult& outDetectionHit)
{
    for (const FHitResult& hit : hits)
    {
        if (UPrimitiveComponent* component = hit.GetComponent())
        {
            if (component->GetCollisionObjectType() == COLLISION_PLAYER)
            {
                //we can't get more important than the player
                outDetectionHit = hit;
                if(lastKnownPosition.Size() == 0) lastKnownPosition = hit.GetActor()->GetActorLocation();
                //GEngine->AddOnScreenDebugMessage(50, 1.f, FColor::Red, TEXT("COLLISION PLAYER"));
                return;
            }
            else if (component->GetCollisionObjectType() == COLLISION_COLLECTIBLE)
            {
                outDetectionHit = hit;
            }
        }
    }
}

void ASDTAIController::SetPlayerBehavior(FHitResult Hit) 
{
    if (Hit.GetComponent()) {
        // cas 1 : player detected
        if (Hit.GetComponent()->GetCollisionObjectType() == COLLISION_PLAYER) {
            movementSpeed = 600.f; // Arbitrary Run Speed

            //GEngine->AddOnScreenDebugMessage(50, 1.f, FColor::Red, TEXT("COLLISION PLAYER BEHAVIOR"));

            if (SDTUtils::IsPlayerPoweredUp(GetWorld())) {

                //GEngine->AddOnScreenDebugMessage(20, 1.f, FColor::Red, TEXT("FLEE POINT"));
                
                //comportement de fuite vers point de fuite le plus pertinent
                GetPathToBestFleePoint(Hit.GetActor()->GetActorLocation());
            }
            else {
                //comportement de poursuite
                bool playerIsVisible = SDTUtils::Raycast(GetWorld(), GetPawn()->GetActorLocation(), Hit.GetActor()->GetActorLocation());
                if (playerIsVisible) {
                    // Joueur visible et non boosté = calcul path et pourchasse
                    lastKnownPosition = Hit.GetActor()->GetActorLocation();
                    //GEngine->AddOnScreenDebugMessage(30, 1.f, FColor::Green, TEXT("PLAYER VISIBLE"));
                    GetPathToActor(lastKnownPosition);
                }
                else if (lastKnownPosition.Size() != 0) {
                    // Joueur non visible et non boosté = déplacement vers LKP
                    //GEngine->AddOnScreenDebugMessage(40, 1.f, FColor::Green, TEXT("LAST KNOWN POSITION"));
                    GetPathToActor(lastKnownPosition);
                    //if reached LastKnownPosition
                    if ((GetPawn()->GetActorLocation() - lastKnownPosition).Size() < 10) {
                        lastKnownPosition = FVector::ZeroVector;
                        AIStateInterrupted();
                    }
                }
            }
        }

        // cas 2 : collectible detected
        else if (Hit.GetComponent()->GetCollisionObjectType() == COLLISION_COLLECTIBLE) {
            //GEngine->AddOnScreenDebugMessage(10, 1.f, FColor::Blue, TEXT("COLLECTIBLE"));

            movementSpeed = 200.f; // Arbitrary Walking Speed
            GetPathToClosestCollectible();
            ShowNavigationPath();
        }
    }
}

void ASDTAIController::AIStateInterrupted()
{
    StopMovement();
    m_ReachedTarget = true;
}