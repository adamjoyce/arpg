// Copyright Adam Joyce. All Rights Reserved.

#include "Arpg.h"
#include "CausticCloud.h"


ACausticCloud::ACausticCloud()
{
	/// Setup the trigger zone.
	DamageZone = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageZone"));
	RootComponent = DamageZone;

	/// Setup the particle system.
	ParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleComponent->SetupAttachment(RootComponent);

	/// Bind for collision notifications.
	DamageZone->OnComponentBeginOverlap.AddDynamic(this, &ACausticCloud::OnOverlapBegin);
	//DamageZone->OnComponentEndOverlap.AddDynamic(this, &ACausticCloud::OnOverlapEnd);
}

void ACausticCloud::OnOverlapBegin(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		UE_LOG(LogTemp, Warning, TEXT("ENTERED"));
	}
}

/* Currently not working due to engine bug... */
//void ACausticCloud::OnOverlapEnd(class UPrimitiveComponent* HitComp, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
//	{
//		UE_LOG(LogTemp, Warning, TEXT("EXITED"));
//	}
//}

void ACausticCloud::ReceiveActorEndOverlap(AActor* OtherActor)
{
	if ((OtherActor != nullptr) && (OtherActor != this))
	{
		UE_LOG(LogTemp, Warning, TEXT("EXITED"));
	}
}
