// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakePart.h"
#include "Kismet/GameplayStatics.h"
#include "SnakeGameMode.h"


// Sets default values
ASnakePart::ASnakePart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add("SnakePart");
}

// Called when the game starts or when spawned
void ASnakePart::BeginPlay()
{
	Super::BeginPlay();

	ASnakeGameMode* GameMode = GetSnakeGameMode();
	if (GameMode)
	{
		GameMode->SetPart(this);
	}


	AGameModeBase* GameModePtr = UGameplayStatics::GetGameMode(GetWorld());
	if (nullptr == GameModePtr)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == GameMode)"), __FUNCTION__, __LINE__);
		return;
	}

	// ���� ���� ���ڷ� �� �ִ� ���ͺ��� ���߿� Tick�� ������.
	// ���� ���ε� GameModePtr���� ���߿� tick�� ������.
	AddTickPrerequisiteActor(GameModePtr);
}

// Called every frame
void ASnakePart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//ASnakePart* Body = static_cast<ASnakePart*>(GetSnakeGameMode()->GetPart(GetActorLocation(), "Body"));
	//ASnakePart* Head = static_cast<ASnakePart*>(GetSnakeGameMode()->GetPart(GetActorLocation(), "Head"));
	//PrevPosition = ASnakePart* PrevHead;
	//
	//if (nullptr != Next)
	//{
	//	ASnakePart* CurNextPart = Next;
	//
	//	while (nullptr != CurNextPart)
	//	{
	//		CurNextPart->PrevPosition = CurNextPart->GetActorLocation();
	//		CurNextPart->SetActorLocation(CurNextPart->Prev->PrevPosition);
	//		CurNextPart = CurNextPart->Next;
	//	}
	//}

	//ASnakePart* Body = static_cast<ASnakePart*>(GetSnakeGameMode()->GetPart(GetActorLocation(), "Body"));
	//ASnakePart* Head = static_cast<ASnakePart*>(GetSnakeGameMode()->GetPart(GetActorLocation(), "Head"));

	//if (Body && Head)
	//{
		//ASnakePart* Prev = Head;

	//	ASnakePart* CurNextPart = Body;

	//	while (CurNextPart)
	//	{
	//		FVector PrevPos = CurNextPart->GetActorLocation();
	//		CurNextPart->SetActorLocation(Prev->GetActorLocation());
	//		CurNextPart->PrevPosition = PrevPos;
	//
	//		Prev->Next = CurNextPart;
	//		Prev = CurNextPart;
	//		CurNextPart = CurNextPart->Next;
	//	}
	//}
	//else
	//{
	//	// Body �Ǵ� Head�� nullptr�� ��� ���� ó��
	//	// ���� �ذ��� ���� ������ ��ġ�� ���ؾ� �մϴ�.
	//}


	
}

ASnakeGameMode* ASnakePart::GetSnakeGameMode()
{
	AGameModeBase* GameModePtr = UGameplayStatics::GetGameMode(GetWorld());
	

	if (nullptr == GameModePtr)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == GameMode)"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	if (false == GameModePtr->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == GameMode)"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	ASnakeGameMode* SnakeGameMode = Cast<ASnakeGameMode>(GameModePtr);

	if (nullptr == SnakeGameMode && false == SnakeGameMode->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == SnakeGameMode && false == SnakeGameMode->IsValidLowLevel())"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	return SnakeGameMode;
}

ASnakePart* ASnakePart::LastNextPart()
{
	if (nullptr != Next)
	{
		return Next->LastNextPart();
	}

	return this;
}

