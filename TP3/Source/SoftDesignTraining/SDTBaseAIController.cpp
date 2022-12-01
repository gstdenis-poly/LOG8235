// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTBaseAIController.h"
#include "SoftDesignTraining.h"
#include "AiAgentGroupManager.h"
#include "AiUpdateTimeSlicer.h"

ASDTBaseAIController::ASDTBaseAIController(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;
    m_ReachedTarget = true;
}

void ASDTBaseAIController::Tick(float deltaTime)
{
    Super::Tick(deltaTime);

    AiAgentGroupManager* m_AiAgentGroupManager = AiAgentGroupManager::GetInstance();
    m_AiAgentGroupManager->DrawSphereOverGroupMembers(deltaTime);

    AiUpdateTimeSlicer* timeSlicer = AiUpdateTimeSlicer::GetInstance();
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::SanitizeFloat(timeSlicer->GetBalance()));
    timeSlicer->Reset();

    /*UpdatePlayerInteraction(deltaTime);

    if (m_ReachedTarget)
    {
        GoToBestTarget(deltaTime);
    }
    else
    {
        ShowNavigationPath();
    }*/
}
