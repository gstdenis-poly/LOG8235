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

void AiUpdateTimeSlicer::Consume(float amount)
{
    m_Balance -= amount;
}

int AiUpdateTimeSlicer::GetBalance()
{
    return m_Balance;
}

void AiUpdateTimeSlicer::Reset()
{
    m_Balance = m_Budget;
    m_ExecutedAIs = 0;
}

int AiUpdateTimeSlicer::GetAICount()
{
    return m_AICount;
}

void AiUpdateTimeSlicer::IncrementAICount()
{
    m_AICount++;
}

void AiUpdateTimeSlicer::IncrementExecutedAIs()
{
    m_ExecutedAIs++;
}

int AiUpdateTimeSlicer::GetExecutedAIs()
{
    return m_ExecutedAIs;
}

bool AiUpdateTimeSlicer::CanExecute() 
{
    if (GetExecutedAIs() == GetAICount()) 
        Reset();

    IncrementExecutedAIs();
    return GetBalance() > 0;
}