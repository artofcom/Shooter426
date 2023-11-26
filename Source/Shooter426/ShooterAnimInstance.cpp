// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAnimInstance.h"
#include "ShooterCharacter.h"
#include "GameFramework/characterMovementComponent.h"

void UShooterAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (ShooterCharacter == nullptr)
		ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
	
	if (ShooterCharacter)
	{
		FVector Velocity{ ShooterCharacter->GetVelocity() };
		Velocity.Z = .0f;
		Speed = Velocity.Size();	// magnitude

		bIsInAir = ShooterCharacter->GetCharacterMovement()->IsFalling();

		bIsAccelerating = (ShooterCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > .0f);
	}
}


void UShooterAnimInstance::NativeInitializeAnimation()
{
	ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
}