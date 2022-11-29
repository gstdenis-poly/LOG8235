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

void AiUpdateTimeSlicer::Consume(double amount)
{
    m_Balance -= amount;
    GEngine->AddOnScreenDebugMessage(97, 5.f, FColor::Blue, FString::SanitizeFloat(m_Budget));
}

double AiUpdateTimeSlicer::GetBalance()
{
    return m_Balance;
}

void AiUpdateTimeSlicer::Reset()
{
    m_Balance = m_Budget;
}