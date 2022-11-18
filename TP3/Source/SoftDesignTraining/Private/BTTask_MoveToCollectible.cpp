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
        //GEngine->AddOnScreenDebugMessage(500, 5.f, FColor::Blue, TEXT("LINKED!!!"));
        //La task est bien exécutée, mais les AIs ne bougent pas.
        //MoveToRandomCollectible devra être modifié.
        aiController->MoveToRandomCollectible();
        return EBTNodeResult::Succeeded;
    }
    return EBTNodeResult::Failed;
}