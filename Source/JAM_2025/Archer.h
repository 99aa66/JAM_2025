// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Archer.generated.h"

UCLASS()
class JAM_2025_API AArcher : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AArcher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// Reference to the player character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	AActor* PlayerActor;

	// Speed at which the AI will follow the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float MovementSpeed = 200.0f;

	// Function to move towards the player
	void FollowPlayer();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
