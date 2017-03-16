// Copyright Adam Joyce. All Rights Reserved.

#include "Arpg.h"
#include "BaseCharacter.h"


ABaseCharacter::ABaseCharacter() : Health(100.0f)
{
 	/// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

float ABaseCharacter::GetHealth() const
{
	return Health;
}

float ABaseCharacter::GetMaxHealth() const
{
	/// Retrieves the default Health value of the class assigned on instantiaion.
	return GetClass()->GetDefaultObject<ABaseCharacter>()->Health;
}

