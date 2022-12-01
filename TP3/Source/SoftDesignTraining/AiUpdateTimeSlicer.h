// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class AiUpdateTimeSlicer
{
public:
    static AiUpdateTimeSlicer* GetInstance();
    static void Destroy();
    void Consume(int amount);
    int GetBalance();
    void Reset();
    int GetThreshold();
    void Increment();
    int GetCounter();

private:
    AiUpdateTimeSlicer();
    static AiUpdateTimeSlicer* m_Instance;

    int m_Budget = 30; // Budget of updates per frame
    int m_Balance = m_Budget;
    int m_Threshold = 56; // Number of AI controllers
    int m_Counter = 0;
};