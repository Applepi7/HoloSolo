#include "stdafx.h"
#include "FifthStage.h"


FifthStage::FifthStage()
{
	background = new ZeroSprite("Resource/UI/Background/background.png");

	dragon = new Dragon();
	player = new PlayerCharacter();
	PushScene(dragon);
	PushScene(player);

	background->SetPos(640 - background->Width() * 0.5f, 355 - background->Height() * 0.5f);
}

void FifthStage::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	player->Update(eTime);
	dragon->Update(eTime);
}

void FifthStage::Render()
{
	ZeroIScene::Render();

	background->Render();

	dragon->Render();
	player->Render();
}
