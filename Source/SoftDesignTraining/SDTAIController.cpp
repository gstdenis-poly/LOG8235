// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "SoftDesignTraining.h"
#include "SoftDesignTrainingCharacter.h"
#include "SDTUtils.h"

void ASDTAIController::Tick(float deltaTime)
{
    DetectPlayer(GetWorld());
    DetectWall();
    DetectDeathFloor();
    MoveForward(deltaTime);
}

bool ASDTAIController::MoveForward(float deltaTime) {
    speed += (ACCELERATION * deltaTime);
    if (speed >= MAX_SPEED) speed = MAX_SPEED;
    FVector disp = speed * deltaTime * direction.GetSafeNormal();
    GetPawn()->AddMovementInput(direction, speed);
    return false;
}

//Le comportement n'est pas parfait, il doit �tre peaufin� (peut-�tre jou� avec les valeurs de d�tection et angle)
//Le code pourra �galement �tre am�lior� (lisbilit�, clart�, �viter redondance avec les autres fonctions)
void ASDTAIController::DetectWall() {
    FHitResult outHits;
    FCollisionObjectQueryParams objectQueryParams;
    objectQueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
    queryParams.bReturnPhysicalMaterial = true;

    FVector forward = direction * OBSTACLE_DETECTION_DISTANCE;

    //Detection du mur devant le AI
    FVector rayEnd = FVector(GetPawn()->GetActorLocation().X + forward.X, GetPawn()->GetActorLocation().Y + forward.Y, GetPawn()->GetActorLocation().Z + forward.Z);
    bool wallDetected = GetWorld()->LineTraceSingleByObjectType(outHits, GetPawn()->GetActorLocation(), rayEnd, objectQueryParams, queryParams);

    if (wallDetected) {
        FHitResult rightHit;
        FHitResult leftHit;
        FVector rayStart = GetPawn()->GetActorLocation();
        FVector rayRight = rayStart + GetPawn()->GetActorRightVector() * 1000;
        FVector rayLeft = rayStart - GetPawn()->GetActorRightVector() * 1000;

        //Determiner si il y a des obstacles sur les cot�s du AI
        bool rightDetected = GetWorld()->LineTraceSingleByObjectType(rightHit, rayStart, rayRight, objectQueryParams, queryParams);
        bool leftDetected = GetWorld()->LineTraceSingleByObjectType(leftHit, rayStart, rayLeft, objectQueryParams, queryParams);

        //D�terminer quel c�t� le AI devrait tourner pour continuer son chemin sans rencontrer un obstacle
        if (rightDetected && leftDetected) {
            if (rightHit.Distance > leftHit.Distance) GetPawn()->AddActorWorldRotation(FRotator(0, rotationAngle, 0), false, (FHitResult*)nullptr, ETeleportType::None);
            else GetPawn()->AddActorWorldRotation(FRotator(0, -rotationAngle, 0), false, (FHitResult*)nullptr, ETeleportType::None);
        }
        else if (leftDetected) GetPawn()->AddActorWorldRotation(FRotator(0, rotationAngle, 0), false, (FHitResult*)nullptr, ETeleportType::None);
        else GetPawn()->AddActorWorldRotation(FRotator(0, -rotationAngle, 0), false, (FHitResult*)nullptr, ETeleportType::None);

        direction = GetPawn()->GetActorForwardVector();
        speed = speed / 1.3;
    }
}

void ASDTAIController::DetectDeathFloor() {
    FHitResult outHits;
    FCollisionObjectQueryParams objectQueryParams;
    objectQueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
    objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    objectQueryParams.AddObjectTypesToQuery(ECC_GameTraceChannel3);
    FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
    queryParams.bReturnPhysicalMaterial = true;

    FVector forward = direction * OBSTACLE_DETECTION_DISTANCE;

    FVector rayStart = FVector(GetPawn()->GetActorLocation().X + forward.X, GetPawn()->GetActorLocation().Y + forward.Y, 1000);
    FVector rayEnd = FVector(GetPawn()->GetActorLocation().X + forward.X, GetPawn()->GetActorLocation().Y + forward.Y, 0); 

    //Detection du deathfloor devant le AI
    bool deathFloorDetected = GetWorld()->LineTraceSingleByObjectType(outHits, rayStart, rayEnd, objectQueryParams, queryParams);

    if (deathFloorDetected && outHits.GetComponent()->GetCollisionObjectType() == COLLISION_DEATH_OBJECT) {
        FHitResult rightHit;
        FHitResult leftHit;
        FVector rayStartRL = GetPawn()->GetActorLocation();
        FVector rayRight = rayStartRL + GetPawn()->GetActorRightVector() * 1000;
        FVector rayLeft = rayStartRL - GetPawn()->GetActorRightVector() * 1000;

        //Determiner si il y a des obstacles sur les cot�s du AI
        bool rightDetected = GetWorld()->LineTraceSingleByObjectType(rightHit, rayStartRL, rayRight, objectQueryParams, queryParams);
        bool leftDetected = GetWorld()->LineTraceSingleByObjectType(leftHit, rayStartRL, rayLeft, objectQueryParams, queryParams);

        //D�terminer quel c�t� le AI devrait tourner pour continuer son chemin sans rencontrer un obstacle
        if (rightDetected && leftDetected) {
            if (rightHit.Distance > leftHit.Distance) GetPawn()->AddActorWorldRotation(FRotator(0, rotationAngle, 0), false, (FHitResult*)nullptr, ETeleportType::None);
            else GetPawn()->AddActorWorldRotation(FRotator(0, -rotationAngle, 0), false, (FHitResult*)nullptr, ETeleportType::None);
        }
        else if (leftDetected) GetPawn()->AddActorWorldRotation(FRotator(0, rotationAngle, 0), false, (FHitResult*)nullptr, ETeleportType::None);
        else GetPawn()->AddActorWorldRotation(FRotator(0, -rotationAngle, 0), false, (FHitResult*)nullptr, ETeleportType::None);

        direction = GetPawn()->GetActorForwardVector();
        speed = speed / 1.3;
    }
}

void ASDTAIController::DetectPlayer(UWorld* uWorld) {
    FHitResult outHit;
    FCollisionObjectQueryParams objectQueryParams;
    objectQueryParams.AddObjectTypesToQuery(ECC_GameTraceChannel4);
    FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
    queryParams.bReturnPhysicalMaterial = true;

    FVector forward = direction * OBSTACLE_DETECTION_DISTANCE;
    FVector rayStart = GetPawn()->GetActorLocation();
    FVector rayEnd = FVector(GetPawn()->GetActorLocation().X + forward.X, GetPawn()->GetActorLocation().Y + forward.Y, GetPawn()->GetActorLocation().Z + forward.Z);

    //D�tecter si il y a un joueur � proximit� de l'AI
    //TODO : revoir l'emplacement et la taille de la sph�re pour d�tecter le joueur
    bool playerDetected = GetWorld()->SweepSingleByObjectType(outHit, rayStart, rayEnd, FQuat::Identity, objectQueryParams, FCollisionShape::MakeSphere(150.0f), queryParams);
    bool playerIsPoweredUp = SDTUtils::IsPlayerPoweredUp(uWorld);

    //D�terminer quel comportement adopter (fuite ou poursuite)
    if (playerDetected && outHit.GetComponent()->GetCollisionObjectType() == COLLISION_PLAYER) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, outHit.GetActor()->GetName());
        if (playerIsPoweredUp) RunAwayFromPlayer(outHit.Location);
        else ChasePlayer(outHit.Location);
    }
}

void ASDTAIController::ChasePlayer(FVector playerPosition) {
    //TODO : ne semble pas bien fonctionner (utiliser une rotation � la place? comme avec detectWall?)
    direction = playerPosition - GetPawn()->GetActorLocation();
}

void ASDTAIController::RunAwayFromPlayer(FVector playerPosition) {
    //TODO : ne semble pas bien fonctionner (utiliser une rotation � la place? comme avec detectWall?)
    direction = GetPawn()->GetActorLocation() - playerPosition;
}