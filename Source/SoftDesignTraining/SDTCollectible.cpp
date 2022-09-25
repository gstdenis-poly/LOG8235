// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTCollectible.h"
#include "SoftDesignTraining.h"

ASDTCollectible::ASDTCollectible()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ASDTCollectible::BeginPlay()
{
    Super::BeginPlay();
}

void ASDTCollectible::Collect()
{
    GetWorld()->GetTimerManager().SetTimer(m_CollectCooldownTimer, this, &ASDTCollectible::OnCooldownDone, m_CollectCooldownDuration, false);
    speed = 0;
    GetStaticMeshComponent()->SetVisibility(false);
}

void ASDTCollectible::OnCooldownDone()
{
    GetWorld()->GetTimerManager().ClearTimer(m_CollectCooldownTimer);

    GetStaticMeshComponent()->SetVisibility(true);
}

bool ASDTCollectible::IsOnCooldown()
{
    return m_CollectCooldownTimer.IsValid();
}

void ASDTCollectible::Tick(float deltaTime)
{
    Super::Tick(deltaTime);
    if (isMoveable) {
        DetectWall();
        MoveForward(deltaTime);
    }
}

bool ASDTCollectible::MoveForward(float deltaTime)
{
    speed += (ACCELERATION * deltaTime);
    if (speed >= MAX_SPEED) speed = MAX_SPEED;
    FVector disp = speed * deltaTime * direction.GetSafeNormal();
    SetActorLocation(GetActorLocation() + disp, true);
    return false;
}

bool ASDTCollectible::DetectWall()
{
    FHitResult outHits;
    FCollisionObjectQueryParams objectQueryParams;
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
    FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
    queryParams.bReturnPhysicalMaterial = true;

    FVector forward = direction * COLLISION_DETECTION_DISTANCE;
    FVector rayEnd = GetActorLocation() + forward;

    bool wallDetected = GetWorld()->LineTraceSingleByObjectType(outHits, GetActorLocation(), rayEnd, objectQueryParams, queryParams);
    if (wallDetected) {
        direction = direction *= -1;
        speed = 0;
        return true;
    }
    return false;
}
