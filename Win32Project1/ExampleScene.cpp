#include "stdafx.h"
#include "ExampleScene.h"
#include "Global.h"

#include <math.h>


ExampleScene::ExampleScene()
{
	background = new ZeroSprite("Resource/UI/Background/background.png");

	
	player = new PlayerCharacter();
	slime = new Slime();
	wisp = new Wisp();
	totem = new Totem();

	PushScene(player);
	PushScene(slime);
	PushScene(wisp);
	PushScene(totem);

	background->SetPos(640 - background->Width() * 0.5f, 355 - background->Height() * 0.5f);
	slime->SetPos(500, 300);

	wisp->SetPos(300, 300);
}

void ExampleScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	player->Update(eTime);
	slime->Update(eTime);
	wisp->Update(eTime);
	
	slime->Follow(player, slime, eTime, slime->isAlive);
	//slime->SelfBoom(player, eTime);

	wisp->Follow(player, wisp, eTime, true);
	wisp->Attack(player);

	if (IsCollision(player, slime))
	{
		printf("Ãæµ¹!");
	}

	printf("%.2f\n", player->Pos().y - slime->Pos().y);
}

void ExampleScene::Render()
{
	ZeroIScene::Render();

	background->Render();

	player->Render();
	slime->Render();
	//wisp->Render();
	totem->Render();
}
