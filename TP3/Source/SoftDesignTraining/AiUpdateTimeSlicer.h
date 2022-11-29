// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class AiUpdateTimeSlicer
{
public:
    static AiUpdateTimeSlicer* GetInstance();
    static void Destroy();
    void Consume(double amount);
    double GetBalance();
    void Reset();

private:
    AiUpdateTimeSlicer();
    static AiUpdateTimeSlicer* m_Instance;

    double m_Budget = 1.0;
    double m_Balance = m_Budget;
};