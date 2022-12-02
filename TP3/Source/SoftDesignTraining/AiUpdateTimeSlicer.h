// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class AiUpdateTimeSlicer
{
public:
    static AiUpdateTimeSlicer* GetInstance();
    static void Destroy();
    void Consume(float amount);
    int GetBalance();
    void Reset();
    int GetAICount();
    void IncrementExecutedAIs();
    int GetExecutedAIs();
    void IncrementAICount();
    bool CanExecute();

private:
    AiUpdateTimeSlicer();
    static AiUpdateTimeSlicer* m_Instance;

    float m_Budget = 100; // Budget in ms for updates per frame (100 ms)
    float m_Balance = m_Budget; // Available budget left for updates for the current frame
    int m_AICount = 0; // Number of AI controllers
    int m_ExecutedAIs = 0; //number of AI executed during the current frame (Incremented for every AIController Tick)
};