// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SDTAIController.h"
#include "CoreMinimal.h"

class SOFTDESIGNTRAINING_API AiAgentGroupManager
{
public:
    static AiAgentGroupManager* GetInstance();
    static void Destroy();

    void RegisterAIAgent(ASDTAIController* aiAgent);
    void UnregisterAIAgent(ASDTAIController* aiAgent);
    void DrawSphereOverGroupMembers();
    void SetChasingPointsAroundTarget();

private:

    AiAgentGroupManager();
    static AiAgentGroupManager* m_Instance;

    TArray<ASDTAIController*> m_registeredAgents;
    FVector m_memberIdentifierLocation = FVector(0.f, 0.f, 100.f);
    FVector m_lastKnownPosition;
};