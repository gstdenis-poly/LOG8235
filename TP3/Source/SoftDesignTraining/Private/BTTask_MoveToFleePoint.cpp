// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveToFleePoint.h"

#include "../SDTAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"


EBTNodeResult::Type UBTTask_MoveToFleePoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
    {
        //Logique pour se déplacer vers un flee point (Flee Mode)
        aiController->MoveToBestFleeLocation();
        return EBTNodeResult::Succeeded;
    }
    return EBTNodeResult::Succeeded;
}