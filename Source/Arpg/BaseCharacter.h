// Copyright Adam Joyce. All Rights Reserved.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class ARPG_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/* Sets default values for this character's properties. */
	ABaseCharacter();

	/* Called when the game starts or when spawned. */
	virtual void BeginPlay() override;
	
	/* Called every frame. */
	virtual void Tick( float DeltaSeconds ) override;

	/* Called to bind functionality to input. */
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


	/************************************************************/
	/* Hitpoints.                                               */
	/************************************************************/

	/* Returns the character's current hitpoint value. */
	UFUNCTION(BlueprintCallable, Category = "CharacterCondition")
	float GetHealth() const;

	/* Returns the character's maximum hitpoint value. */
	UFUNCTION(BlueprintCallable, Category = "CharacterCondition")
	float GetMaxHealth() const;


	/************************************************************/
	/* Damage, Hits, and Death.                                 */
	/************************************************************/

	/* Causes the character to take hitpoint damage. */
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

private:
	/************************************************************/
	/* Hitpoints.                                               */
	/************************************************************/

	/* The health in hitpoints of the character. */
	UPROPERTY(EditDefaultsOnly, Category = "CharacterCondition")
	float Health;


	/************************************************************/
	/* Damage, Hits, and Death.                                 */
	/************************************************************/
};
