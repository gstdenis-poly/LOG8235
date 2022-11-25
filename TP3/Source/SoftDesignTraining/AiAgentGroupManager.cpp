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
    m_registeredAgents.AddUnique(aiAgent);
    GetChasingPointsAroundTarget();
}

void AiAgentGroupManager::UnregisterAIAgent(ASDTAIController* aiAgent)
{
    m_registeredAgents.Remove(aiAgent);
    GetChasingPointsAroundTarget();
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

void AiAgentGroupManager::GetChasingPointsAroundTarget()
{
    if (m_registeredAgents.Num() < 1) return; // Pour 1 agent on garde la LastKnownPosition comme point d'attaque

    m_attackPoints.Empty();

    float angle = 2.f * PI / (float)m_registeredAgents.Num();
    float currentAngle = 0.f;

    for (int i = 0; i < m_registeredAgents.Num(); i++)
    {
        m_attackPoints.Add(FVector(m_lastKnownPosition.X + m_rayon * cos(currentAngle), m_lastKnownPosition.Y + m_rayon * sin(currentAngle), m_lastKnownPosition.Z));
        currentAngle += angle;
    }
}

void AiAgentGroupManager::AssignChasingPointsToAIs()
{
    for (int i = 0; i < m_registeredAgents.Num(); i++)
    {
        m_registeredAgents[i]->m_attackPoint = m_attackPoints[i];
        //TODO : Assigner chaque point d'attaque à un AI
        //Idéalement à l'AI le plus proche et en évitant que celui-ci doive passer au travers du cercle pour y arriver.
        

        /*for (int j = 0; j < m_attackPoints.Num(); j++) {

        }*/
    }
}