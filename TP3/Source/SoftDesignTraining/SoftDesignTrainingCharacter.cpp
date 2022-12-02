// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "SoftDesignTrainingCharacter.h"
#include "SoftDesignTraining.h"
#include "SoftDesignTrainingMainCharacter.h"
#include "SDTAIController.h"
#include "SDTProjectile.h"
#include "SDTUtils.h"
#include "DrawDebugHelpers.h"
#include "SDTCollectible.h"
#include "AiAgentGroupManager.h"
#include "AiUpdateTimeSlicer.h"


ASoftDesignTrainingCharacter::ASoftDesignTrainingCharacter()
{
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
}

void ASoftDesignTrainingCharacter::BeginPlay()
{
    Super::BeginPlay();

    GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ASoftDesignTrainingCharacter::OnBeginOverlap);
    m_StartingPosition = GetActorLocation();
}

void ASoftDesignTrainingCharacter::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherComponent->GetCollisionObjectType() == COLLISION_DEATH_OBJECT)
    {
        Die();
    }
    else if(ASDTCollectible* collectibleActor = Cast<ASDTCollectible>(OtherActor))
    {
        if (!collectibleActor->IsOnCooldown())
        {
            OnCollectPowerUp();
        }

        collectibleActor->Collect();
    }
    else if (ASoftDesignTrainingMainCharacter* mainCharacter = Cast<ASoftDesignTrainingMainCharacter>(OtherActor))
    {
        if (mainCharacter->IsPoweredUp())
            Die();
    }
}

void ASoftDesignTrainingCharacter::Die()
{
    SetActorLocation(m_StartingPosition);

    if (ASDTAIController* controller = Cast<ASDTAIController>(GetController()))
    {
        controller->AIStateInterrupted();
    }
}

void ASoftDesignTrainingCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    AiAgentGroupManager* aiAgentGroupManager = AiAgentGroupManager::GetInstance();
    if (aiAgentGroupManager)
    {
        aiAgentGroupManager->Destroy();
    }

    AiUpdateTimeSlicer* aiUpdateTimeSlicer = AiUpdateTimeSlicer::GetInstance();
    if (aiUpdateTimeSlicer)
    {
        aiUpdateTimeSlicer->Destroy();
    }
}
