// Fill out your copyright notice in the Description page of Project Settings.

#include "AiUpdateTimeSlicer.h"

AiUpdateTimeSlicer* AiUpdateTimeSlicer::m_Instance;

AiUpdateTimeSlicer::AiUpdateTimeSlicer()
{
}

AiUpdateTimeSlicer* AiUpdateTimeSlicer::GetInstance()
{
    if (!m_Instance)
    {
        m_Instance = new AiUpdateTimeSlicer();
    }

    return m_Instance;
}

void AiUpdateTimeSlicer::Destroy()
{
    delete m_Instance;
    m_Instance = nullptr;
}

// M�thode pour consommer le temps CPU du budget
void AiUpdateTimeSlicer::Consume(float amount)
{
    m_Balance -= amount;
}

int AiUpdateTimeSlicer::GetBalance()
{
    return m_Balance;
}

// M�thode pour r�initialiser le budget � chaque frame
void AiUpdateTimeSlicer::Reset()
{
    m_Balance = m_Budget;
    m_ExecutedAIs = 0;
}

int AiUpdateTimeSlicer::GetAICount()
{
    return m_AICount;
}

// Initialisation du nombre de AIs sur la map
void AiUpdateTimeSlicer::IncrementAICount(FString aiLabel)
{
    m_AICount++;
    m_nonExecutedControllers.AddUnique(aiLabel);
}

void AiUpdateTimeSlicer::IncrementExecutedAIs()
{
    m_ExecutedAIs++;
}

int AiUpdateTimeSlicer::GetExecutedAIs()
{
    return m_ExecutedAIs;
}

// M�thode pour savoir si les agents peuvent ex�cuter leur update dans la frame en cours
bool AiUpdateTimeSlicer::CanExecute(FString aiLabel)
{
    if (GetExecutedAIs() == GetAICount()) 
        Reset();

    IncrementExecutedAIs();

    if (m_nonExecutedControllers.Num() == 0) 
    {
        m_nonExecutedControllers = m_executedControllers;
        m_executedControllers.Empty();
    }

    if (GetBalance() > 0 && m_nonExecutedControllers.Contains(aiLabel)) 
    {
        m_nonExecutedControllers.Remove(aiLabel);
        m_executedControllers.AddUnique(aiLabel);
        return true;
    }

    return false;
}