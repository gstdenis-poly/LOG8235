// Fill out your copyright notice in the Description page of Project Settings.

#include "AiAgentGroupManager.h"
#include "SDTAIController.h"

AiAgentGroupManager* AiAgentGroupManager::m_Instance;

AiAgentGroupManager::AiAgentGroupManager()
{
}

AiAgentGroupManager* AiAgentGroupManager::GetInstance()
{
    if (!m_Instance)
    {
        m_Instance = new AiAgentGroupManager();
    }

    return m_Instance;
}

void AiAgentGroupManager::Destroy()
{
    delete m_Instance;
    m_Instance = nullptr;
}

void AiAgentGroupManager::RegisterAIAgent(ASDTAIController* aiAgent)
{
    m_registeredAgents.Add(aiAgent);
}

void AiAgentGroupManager::UnregisterAIAgent(ASDTAIController* aiAgent)
{
    m_registeredAgents.Remove(aiAgent);
}

void AiAgentGroupManager::DrawSphereOverGroupMembers()
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

void AiAgentGroupManager::SetChasingPointsAroundTarget()
{
    //TODO : pour l'encerclement du joueur par les agents
}