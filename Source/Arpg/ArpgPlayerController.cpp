// Copyright Adam Joyce. All Rights Reserved.

#include "Arpg.h"
#include "ArpgPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"

AArpgPlayerController::AArpgPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AArpgPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	/// Keep updating the destination every tick while desired.
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void AArpgPlayerController::SetupInputComponent()
{
	/// Set up gameplay key bindings.
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AArpgPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AArpgPlayerController::OnSetDestinationReleased);

	/// Support touch devices.
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AArpgPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AArpgPlayerController::MoveToTouchLocation);
}

void AArpgPlayerController::MoveToMouseCursor()
{
	/// Trace to see what is under the mouse cursor.
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		/// We hit something, move there.
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void AArpgPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	/// Trace to see what is under the touch location.
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		/// We hit something, move there.
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AArpgPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(DestLocation, Pawn->GetActorLocation());

		/// We need to issue move command only if far enough in order for walk animation to play correctly.
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AArpgPlayerController::OnSetDestinationPressed()
{
	/// Set flag to keep updating destination until released.
	bMoveToMouseCursor = true;
}

void AArpgPlayerController::OnSetDestinationReleased()
{
	/// Clear flag to indicate we should stop updating the destination.
	bMoveToMouseCursor = false;
}
