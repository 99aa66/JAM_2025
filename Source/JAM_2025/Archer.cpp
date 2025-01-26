// Fill out your copyright notice in the Description page of Project Settings.


#include "Archer.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AArcher::AArcher()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;


}
// Called to bind functionality to input
void AArcher::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Called when the game starts or when spawned
void AArcher::BeginPlay()
{
	Super::BeginPlay();

	PlayerActor = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	
}

// Called every frame
void AArcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerActor)
	{
		FollowPlayer();
	}
}

void AArcher::FollowPlayer()
{
	if (!PlayerActor) return;

	// Get the navigation system
	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	if (!NavSystem) return;

	// Get the player's location
	FVector PlayerLocation = PlayerActor->GetActorLocation();

	// Request the AI to move towards the player
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetController(), PlayerLocation);
}



