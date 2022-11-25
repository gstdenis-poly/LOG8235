// Fill out your copyright notice in the Description page of Project Settings.

#include "AiGroupManager.h"
#include "../SDTAIController.h"

AiGroupManager* AiGroupManager::m_Instance;

AiGroupManager::AiGroupManager()
{
}

AiGroupManager* AiGroupManager::GetInstance()
{
    if (!m_Instance)
    {
        m_Instance = new AiGroupManager();
    }

    return m_Instance;
}

void AiGroupManager::Destroy()
{
    delete m_Instance;
    m_Instance = nullptr;
}

void AiGroupManager::RegisterAIAgent(ASDTAIController* aiAgent)
{
    m_registeredAgents.Add(aiAgent);
}

void AiGroupManager::UnregisterAIAgent(ASDTAIController* aiAgent)
{
    m_registeredAgents.Remove(aiAgent);
}

void AiGroupManager::DrawSphereOverGroupMembers()
{
    for (int i = 0; i < m_registeredAgents.Num(); i++)
    {
        if (ASDTAIController* aicontroller = m_registeredAgents[i])
        {
            FVector actorLocation = aicontroller->GetPawn()->GetActorLocation();
            DrawDebugSphere(aicontroller->GetWorld(), actorLocation + m_memberIdentifierLocation, 25.0f, 32, FColor::Red);
        }
    }
}

void AiGroupManager::SetChasingPointsAroundTarget()
{
    //TODO : pour l'encerclement du joueur par les agents
}
