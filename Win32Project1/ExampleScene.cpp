#include "stdafx.h"
#include "ExampleScene.h"

#include <math.h>


ExampleScene::ExampleScene()
{
	background = new ZeroSprite("Resource/UI/Background/background.png");

	player = new PlayerCharacter();
	slime = new Slime();
	PushScene(background);
	PushScene(player);
	PushScene(slime);

	background->SetPos(640 - background->Width() * 0.5f, 355 - background->Height() * 0.5f);
	slime->SetPos(100, 100);
}

ExampleScene::~ExampleScene()
{
}

void ExampleScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	player->Update(eTime);
	slime->Update(eTime);

	slime->Follow(player, slime, eTime, slime->isAlive);
	slime->SelfBoom(player, eTime);
}

void ExampleScene::Render()
{
	ZeroIScene::Render();

	background->Render();

	player->Render();
	slime->Render();
}
