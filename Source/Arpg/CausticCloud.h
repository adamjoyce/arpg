// Copyright Adam Joyce. All Rights Reserved.

#pragma once

#include "BaseCharacter.h"
#include "GameFramework/Actor.h"
#include "CausticCloud.generated.h"

UCLASS()
class ARPG_API ACausticCloud : public AActor
{
	GENERATED_BODY()
	
public:	
	/* Sets default values for this actor's properties. */
	ACausticCloud();

	/* The collision box component used to detect characters. */
	UPROPERTY(VisibleAnywhere, Category = "Collision")
	UBoxComponent* DamageZone;

	/* The particle system for visibility in the scene. */
	UPROPERTY(VisibleAnywhere, Category = "Visual")
	UParticleSystemComponent* ParticleComponent;

	/* Handle to manage damage over time timer. */
	FTimerHandle DotTimerHandle;

	/* The amount of damage taken each tick. */
	float Damage;

	/* The amount of time between damage ticks. */
	float TimeBetweenDamage;

	/* Begins damaging characters when they enter the zone. */
	UFUNCTION(BlueprintCallable, Category = "Collision")
	void OnOverlapBegin(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FFromSweep, const FHitResult& SweepResult);

	/* Stops damaging characters when they leave the zone. */
	/* Not working due to engine bug... */
	/*UFUNCTION(BlueprintCallable, Category = "Collision")
	void OnOverlapEnd(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);*/

	/* Stops damaging characters when they leave the zone. */
	UFUNCTION(BlueprintCallable, Category = "Collision")
	void ReceiveActorEndOverlap(AActor* OtherActor);

private:
};
