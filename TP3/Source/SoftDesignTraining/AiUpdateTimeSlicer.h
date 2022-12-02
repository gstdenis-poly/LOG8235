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
    void IncrementAICount(FString aiLabel);
    bool CanExecute(FString aiLabel);

private:
    AiUpdateTimeSlicer();
    static AiUpdateTimeSlicer* m_Instance;

    float m_Budget = 33.0; // Budget in ms for updates per frame (33 ms par frame)
    float m_Balance = m_Budget; // Available budget left for updates for the current frame
    int m_AICount = 0; // Number of AI controllers
    int m_ExecutedAIs = 0; //number of AI executed during the current frame (Incremented for every AIController Tick)

    // Used to guarantee that every AI is updated once before some AIs are updated multiple times
    TArray<FString> m_executedControllers; // All controllers executed once recently
    TArray<FString> m_nonExecutedControllers; // All controllers in need to be updated soon
};