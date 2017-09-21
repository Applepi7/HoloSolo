#include "stdafx.h"
#include "ExampleScene.h"


ExampleScene::ExampleScene()
{
	player = new PlayerCharacter();
	PushScene(player);
}


ExampleScene::~ExampleScene()
{
}

void ExampleScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	player->Update(eTime);
}

void ExampleScene::Render()
{
	ZeroIScene::Render();

	player->Render();
}
