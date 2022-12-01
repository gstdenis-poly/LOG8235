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

void AiUpdateTimeSlicer::Consume(int amount)
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
    m_Counter = 0;
}

int AiUpdateTimeSlicer::GetThreshold()
{
    return m_Threshold;
}

void AiUpdateTimeSlicer::Increment()
{
    m_Counter++;
}

int AiUpdateTimeSlicer::GetCounter()
{
    return m_Counter;
}