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

void AiAgentGroupManager::DrawSphereOverGroupMembers(float deltaTime)
{
    for (int i = 0; i < m_registeredAgents.Num(); i++)
    {
        if (ASDTAIController* aicontroller = m_registeredAgents[i])
        {
            FVector actorLocation = aicontroller->GetPawn()->GetActorLocation();
            DrawDebugSphere(aicontroller->GetWorld(), actorLocation + m_memberIdentifierLocation, deltaTime, 32, FColor::Red);
        }
    }
}

void AiAgentGroupManager::GetChasingPointsAroundTarget()
{
    if (m_registeredAgents.Num() == 0) return;
    else if (m_registeredAgents.Num() == 1) {
        m_registeredAgents[0]->SetAttackPoint(m_lastKnownPosition);
        return;
    }

    m_attackPoints.Empty();

    float angle = 2.f * PI / (float)m_registeredAgents.Num();
    float currentAngle = 0.f;

    for (int i = 0; i < m_registeredAgents.Num(); i++)
    {
        m_attackPoints.Add(FVector(m_lastKnownPosition.X + m_rayon * cos(currentAngle), m_lastKnownPosition.Y + m_rayon * sin(currentAngle), m_lastKnownPosition.Z));
        currentAngle += angle;
    }

    AssignChasingPointsToAIs();
}

void AiAgentGroupManager::AssignChasingPointsToAIs()
{
    m_assignedAttackPoints.Empty();
    for (int i = 0; i < m_registeredAgents.Num(); i++)
    {
        float shortestDistanceToAttackPoint = 1000000000.f;
        int index = 0;
        FVector AiLocation = m_registeredAgents[i]->GetPawn()->GetActorLocation();

        for (int j = 0; j < m_attackPoints.Num(); j++) {
            if (!m_assignedAttackPoints.Contains(m_attackPoints[j])) {
                float distance = sqrt(pow(AiLocation.X - m_attackPoints[j].X, 2) + pow(AiLocation.Y - m_attackPoints[j].Y, 2) + pow(AiLocation.Z - m_attackPoints[j].Z, 2));

                if (distance < shortestDistanceToAttackPoint) {
                    index = j;
                    shortestDistanceToAttackPoint = distance;
                }
            }
        }
        m_registeredAgents[i]->SetAttackPoint(m_attackPoints[index]);
        m_assignedAttackPoints.AddUnique(m_attackPoints[index]);
    }
}