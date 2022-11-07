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
	//Set the movement speed based on the selected behavior
	GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = movementSpeed;

	MoveToLocation(targetPosition);
	ShowNavigationPath();
	m_ReachedTarget = targetPosition.X == 0 && targetPosition.Y == 0;
}

UNavigationPath* ASDTAIController::GetPathToClosestCollectible()
{
	//Getting the position of all the collectibles
	TArray<AActor*> collectibles = TArray<AActor*>();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASDTCollectible::StaticClass(), collectibles);

	float currentPathLength = 1000000000000.f;
	UNavigationPath* shortestPath = nullptr;
	AActor* closestActor = collectibles[0];

	//Computing path for each collectible and finding the closest one to the AI that is not on cool down
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
	//Finding the path to the play and targeting the actorPosition
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

	m_ReachedTarget = !AtJumpSegment;
}

void ASDTAIController::ShowNavigationPath()
{
	//Finding the current path followed by the player based on the targetPosition
	UNavigationSystemV1* navigationSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
	UNavigationPath* path = navigationSystem->FindPathToLocationSynchronously(GetWorld(), GetPawn()->GetActorLocation(), targetPosition);

	//Show current navigation path DrawDebugLine and DrawDebugSphere
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
	//If no player, juste gather power ups
	//Commented to make the simulation mode work
	//if (!playerCharacter)
	//    return;

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
				//If no previous lastKnowPosition
				if (lastKnownPosition.Size() == 0) lastKnownPosition = hit.GetActor()->GetActorLocation();
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
	if (!SDTUtils::IsPlayerPoweredUp(GetWorld())) {
		if (isFleeing)
			m_ReachedTarget = true;
		isFleeing = false;
	}

	if (Hit.GetComponent()) {
		// If we detected the player and is visible (raycast)
		if (Hit.GetComponent()->GetCollisionObjectType() == COLLISION_PLAYER && !SDTUtils::Raycast(GetWorld(), GetPawn()->GetActorLocation() + FVector(0, 0, 100), Hit.GetActor()->GetActorLocation() + FVector(0, 0, 100))) {

			movementSpeed = runSpeed;
			// we consider goal reached in order to stop from going to collectible for example
			m_ReachedTarget = true;

			if (SDTUtils::IsPlayerPoweredUp(GetWorld())) {
				//fleeing mode
				lastKnownPosition = FVector::ZeroVector;
				GetPathToBestFleePoint(Hit.GetActor()->GetActorLocation());

				isFleeing = true;
			}
			else {
				//updating the lastKnownPosition
				lastKnownPosition = Hit.GetActor()->GetActorLocation();
			}
		}
	}

	if (!isFleeing) {
		if (lastKnownPosition != FVector::ZeroVector) {
			//Moving towards lastKnownPosition
			GetPathToActor(lastKnownPosition);
			
			//if we reached the lastKnownPosition, interrupt the behavior
			if (FVector::Dist(GetPawn()->GetActorLocation(), lastKnownPosition) < 60) {
				lastKnownPosition = FVector::ZeroVector;
				AIStateInterrupted();
			}
		}
		else {
			//No lastKnownPosition so we are chasing collectibles in walking speed
			movementSpeed = walkSpeed;
			GetPathToClosestCollectible();
		}
	}
}

void ASDTAIController::AIStateInterrupted()
{
	StopMovement();
	m_ReachedTarget = true;
}

void ASDTAIController::Tick(float deltaTime) {

	// if a collectible just got collected and not inAir, forece path recalculation by setting reached target to true
	if (needToRelocate && !InAir) {
		needToRelocate = false;
		m_ReachedTarget = true;
	}

	Super::Tick(deltaTime);

}