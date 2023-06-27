// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeHead.h"
#include "SnakeGameMode.h"
#include "SnakePart.h"

// Sets default values
ASnakeHead::ASnakeHead()
{
	// 언리얼에서 프레임마다 Tick을 돌려야 하는 액터는
	// PrimaryActorTick.bCanEverTick = true; 로 만들어줘야 Tick을 돌릴수가 있습니다.

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// 생성자에서 보통 설정해주는게 일반적인데. 
	// 틱을 돌릴거냐 말거냐
	PrimaryActorTick.bCanEverTick = true;
	// PrimaryActorTick.TickGroup = ETickingGroup::TG_PrePhysics;


}

// Called when the game starts or when spawned
void ASnakeHead::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASnakeHead::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}






void ASnakeHead::LeftMove(float _Value)
{
	if (moveValue::RIGHT == moveValue && 0 == _Value)
	{
		return;
	}
	   moveValue = moveValue::LEFT;
	   AddActorLocalOffset(FVector::LeftVector);

}

void ASnakeHead::RightMove(float _Value)
{
	if (moveValue::LEFT == moveValue && 0 == _Value)
	{
		return;
	}
	   moveValue = moveValue::RIGHT;
       AddActorLocalOffset(FVector::RightVector);
}
void ASnakeHead::UpMove(float _Value)
{
	if (moveValue::DOWN == moveValue && 0 == _Value)
	{
		return;
	}
	moveValue = moveValue::UP;
	AddActorLocalOffset(FVector::UpVector);
}
void ASnakeHead::DownMove(float _Value)
{
	if (moveValue::UP == moveValue && 0 == _Value)
	{
		return;
	}
	moveValue = moveValue::DOWN;
	AddActorLocalOffset(FVector::DownVector);
}


void ASnakeHead::LeftAction()
{
	PrevPos = GetActorLocation();
	//AddPos(MovePos);

	FVector MovePos = FVector::LeftVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	if (moveValue::RIGHT == moveValue)
	{
		return;
	}
	moveValue = moveValue::LEFT;
	//

	//AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
	//AActor* Head = GetSnakeGameMode()->GetPart(GetActorLocation(), "Head");
	//AActor* Prev = Head;

	//AActor* CurNextPart = Body;

	//while (nullptr != CurNextPart)
	//{
		//CurNextPart->  = CurNextPart->GetActorLocation();
		//CurNextPart->SetActorLocation(CurNextPart->Body->PrevPos);
		//CurNextPart = CurNextPart->Next;
		//FVector PrevPos = CurNextPart->GetActorLocation();
		//CurNextPart->SetActorLocation(Prev->GetActorLocation());
		//CurNextPart->PrevPos = PrevPos;

		//Prev = CurNextPart;
		//CurNextPart = CurNextPart->Next;
	//}
	//PrevFVector= FVector::LeftVector;
	//FTransform PrevVec(PrevFVector);
	//AActor* PrevActor;

	//

	AddActorLocalOffset(FVector::LeftVector * 100.0f);

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	
	
		//FVector::LeftVector * 100.0f
		// Body 생성
		FTransform Trans;
		Trans.SetLocation(GetActorLocation() - PrevPos );

		AActor* NewBody = GetWorld()->SpawnActor<ASnakePart>(BodyType, Trans);
		if (NewBody)
		{
			GetSnakeGameMode()->SetPart(NewBody);
			ASnakePart* SnakePart = Cast<ASnakePart>(NewBody);
			if (SnakePart)
			{
				SnakePart->Next = this;
				Prev = SnakePart;
				int a = 0;
			}
		}
	  
	}


	
	
}
void ASnakeHead::RightAction()
{

	FVector MovePos = FVector::RightVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	if (moveValue::LEFT == moveValue)
	{
		return;
	}
	moveValue = moveValue::RIGHT;
	//

	AddActorLocalOffset(FVector::RightVector * 100.0f);

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	    

		FTransform Trans;
		Trans.SetLocation(GetActorLocation() - PrevPos);

		AActor* NewBody = GetWorld()->SpawnActor<ASnakePart>(BodyType, Trans);
		if (NewBody)
		{
			GetSnakeGameMode()->SetPart(NewBody);
			ASnakePart* SnakePart = Cast<ASnakePart>(NewBody);
			if (SnakePart)
			{
				SnakePart->Next = this;
				Prev = SnakePart;
			}
		}
	}

}
void ASnakeHead::UpAction()
{

	FVector MovePos = FVector::UpVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	if (moveValue::DOWN == moveValue)
	{
		return;
	}
	moveValue = moveValue::UP;
	//

	AddActorLocalOffset(FVector::UpVector * 100.0f);

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();

		FTransform Trans;
		Trans.SetLocation(GetActorLocation() - PrevPos);

		AActor* NewBody = GetWorld()->SpawnActor<ASnakePart>(BodyType, Trans);
		if (NewBody)
		{
			GetSnakeGameMode()->SetPart(NewBody);
			ASnakePart* SnakePart = Cast<ASnakePart>(NewBody);
			if (SnakePart)
			{
				SnakePart->Next = this;
				Prev = SnakePart;
			}
		}
	}

}
void ASnakeHead::DownAction()
{

	FVector MovePos = FVector::DownVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	if (moveValue::UP == moveValue)
	{
		return;
	}
	moveValue = moveValue::DOWN;


	// 이동을 하고 나서
	AddActorLocalOffset(FVector::DownVector * 100.0f);

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();

		FTransform Trans;
		Trans.SetLocation(GetActorLocation() - PrevPos);

		AActor* NewBody = GetWorld()->SpawnActor<ASnakePart>(BodyType, Trans);
		if (NewBody)
		{
			GetSnakeGameMode()->SetPart(NewBody);
			ASnakePart* SnakePart = Cast<ASnakePart>(NewBody);
			if (SnakePart)
			{
				SnakePart->Next = this;
				Prev = SnakePart;
			}
		}
	}

}



/*
void ASnakeHead::LeftAction()
{
	FVector NewLocation = GetActorLocation() + FVector::LeftVector * TileSize.X;

	ASnakeGameMode* GameMode = GetWorld()->GetAuthGameMode<ASnakeGameMode>();
	if (GameMode)
	{
		GameMode->SpawnSnakeBody(NewLocation);
	}

	SetActorLocation(NewLocation);
}

void ASnakeHead::RightAction()
{
	FVector NewLocation = GetActorLocation() + FVector::RightVector * TileSize.X;

	ASnakeGameMode* GameMode = GetWorld()->GetAuthGameMode<ASnakeGameMode>();
	if (GameMode)
	{
		GameMode->SpawnSnakeBody(NewLocation);
	}

	SetActorLocation(NewLocation);
}

void ASnakeHead::UpAction()
{
	FVector NewLocation = GetActorLocation() + FVector::UpVector * TileSize.Y;

	ASnakeGameMode* GameMode = GetWorld()->GetAuthGameMode<ASnakeGameMode>();
	if (GameMode)
	{
		GameMode->SpawnSnakeBody(NewLocation);
	}

	SetActorLocation(NewLocation);
}

void ASnakeHead::DownAction()
{
	FVector NewLocation = GetActorLocation() + FVector::DownVector * TileSize.Y;

	ASnakeGameMode* GameMode = GetWorld()->GetAuthGameMode<ASnakeGameMode>();
	if (GameMode)
	{
		GameMode->SpawnSnakeBody(NewLocation);
	}

	SetActorLocation(NewLocation);
}

*/

