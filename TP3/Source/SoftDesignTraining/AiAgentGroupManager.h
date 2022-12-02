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
    void GetChasingPointsAroundTarget();
    void AssignChasingPointsToAIs();
    void SetLastKnownPosition(FVector lkp) { m_lastKnownPosition = lkp; }

private:

    AiAgentGroupManager();
    static AiAgentGroupManager* m_Instance; // Instance singleton

    TArray<ASDTAIController*> m_registeredAgents; // Liste des AIs membres du groupe
    FVector m_memberIdentifierLocation = FVector(0.f, 0.f, 100.f); // Pour afficher l'indicateur au dessus de la tête des agents
    FVector m_lastKnownPosition; // La dernière position vue par le groupe
    TArray<FVector> m_attackPoints; // Liste des points d'attaques
    TArray<FVector> m_assignedAttackPoints; // Pour l'assignation logique des points d'attaques au joueur
    float m_rayon = 100.f; // Rayon autour du joueur pour l'encercler
};