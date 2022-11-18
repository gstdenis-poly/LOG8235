// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveToPlayer.h"

#include "../SDTAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"


EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
    {
        //Impl�menter logique pour se d�placer vers le joueur (Chase Mode)
        return EBTNodeResult::Succeeded;
    }
    return EBTNodeResult::Failed;
}