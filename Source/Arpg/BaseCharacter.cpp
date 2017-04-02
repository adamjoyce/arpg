// Copyright Adam Joyce. All Rights Reserved.

#include "Arpg.h"
#include "BaseCharacter.h"


ABaseCharacter::ABaseCharacter() : Health(100.0f),
								   IsDotted(false)
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

float ABaseCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	if (Health <= 0.0f)
	{
		/// The character is already dead / dying.
		return 0.0f;
	}

	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.0f)
	{
		Health -= ActualDamage;
		if (Health <= 0.0f)
		{
			/// Die...
		}
	}

	return ActualDamage;
}

float ABaseCharacter::TakeDamageOverTime(float Damage, float TimeBetweenDamage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	float TotalDamageTaken = 0;

	if (!IsDotted)
	{
		IsDotted = true;

		FTimerDelegate TimerDelegate = FTimerDelegate::CreateUFunction(this, FName("TakeDamage"), Damage, DamageEvent, EventInstigator, DamageCauser);
		if (GetWorld())
		{
			/// Activate the dot effect.
			GetWorld()->GetTimerManager().SetTimer(DotTimerHandle, TimerDelegate, TimeBetweenDamage, true);
		}
	}
	
	return TotalDamageTaken;
}

bool ABaseCharacter::GetIsDotted()
{
	return IsDotted;
}

void ABaseCharacter::SetIsDotted(bool IsDotted_)
{
	IsDotted = IsDotted_;
}

void ABaseCharacter::PrintDamage()
{
	UE_LOG(LogTemp, Warning, TEXT("DAMAGE"));
}

