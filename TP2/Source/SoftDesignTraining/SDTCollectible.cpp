// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTCollectible.h"
#include "SoftDesignTraining.h"
#include "SDTAIController.h"

ASDTCollectible::ASDTCollectible()
{

}

void ASDTCollectible::Collect()
{
    GetWorld()->GetTimerManager().SetTimer(m_CollectCooldownTimer, this, &ASDTCollectible::OnCooldownDone, m_CollectCooldownDuration, false);

    GetStaticMeshComponent()->SetVisibility(false);
    //upon collecting we need to recalculate the path of AIs that were headed to this location in case they were heading to the collectible
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASDTAIController::StaticClass(), FoundActors);
    // if m_reachedtarget is set to true will inAir the AI will freeze, we prevent this by notifying they need to relocate
    for (AActor* a : FoundActors) {
        
        ASDTAIController* controller = Cast<ASDTAIController>(a);
        if (controller->targetPosition == GetActorLocation()) {
            controller->setNeedToRelocate();
        }
    }
}

void ASDTCollectible::OnCooldownDone()
{
    GetWorld()->GetTimerManager().ClearTimer(m_CollectCooldownTimer);

    GetStaticMeshComponent()->SetVisibility(true);
}

bool ASDTCollectible::IsOnCooldown()
{
    return m_CollectCooldownTimer.IsValid();
}
