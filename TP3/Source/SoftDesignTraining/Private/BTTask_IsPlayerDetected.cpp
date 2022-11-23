// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_IsPlayerDetected.h"
#include "../SDTAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"


EBTNodeResult::Type UBTTask_IsPlayerDetected::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
    {
        //Logique pour récupérer l'état de détection
        if (OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Bool>(aiController->GetPlayerSeenKeyID())) {
            return EBTNodeResult::Succeeded;
        }
        return EBTNodeResult::Failed;
    }
    return EBTNodeResult::Failed;
}