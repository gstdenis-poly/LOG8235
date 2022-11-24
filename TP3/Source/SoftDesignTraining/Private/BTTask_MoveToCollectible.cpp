// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveToCollectible.h"
#include "../SDTAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"


EBTNodeResult::Type UBTTask_MoveToCollectible::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
    {
        //Logique pour se d�placer vers un collectible
        aiController->MoveToRandomCollectible();  
        return EBTNodeResult::Succeeded;
    }
    return EBTNodeResult::Failed;
}