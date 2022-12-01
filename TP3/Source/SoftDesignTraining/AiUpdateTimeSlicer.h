// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class AiUpdateTimeSlicer
{
public:
    static AiUpdateTimeSlicer* GetInstance();
    static void Destroy();
    void Consume(int amount);
    int GetBalance();
    void Reset();

private:
    AiUpdateTimeSlicer();
    static AiUpdateTimeSlicer* m_Instance;

    int m_Budget = 30;
    int m_Balance = m_Budget;
};