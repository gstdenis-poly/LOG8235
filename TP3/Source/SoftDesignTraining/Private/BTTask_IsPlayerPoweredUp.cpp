// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_IsPlayerPoweredUp.h"

#include "../SDTAIController.h"
#include "../SDTUtils.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"


EBTNodeResult::Type UBTTask_IsPlayerPoweredUp::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (SDTUtils::IsPlayerPoweredUp(GetWorld())) return EBTNodeResult::Succeeded;
	return EBTNodeResult::Failed;
}