#include "stdafx.h"
#include "ThirdStage.h"

#include "Random.h"


ThirdStage::ThirdStage()
{
	background = new ZeroSprite("Resource/UI/Background/background.png");

	for (int i = 1; i <= 5; i++)
	{
		Totem* totem = new Totem();
		totem->SetPos(background->Pos().x + 100, background->Pos().y + 100 * i);
		totemList.push_back(totem);
		PushScene(totem);
	}

	player = new PlayerCharacter();
	PushScene(player);

	background->SetPos(640 - background->Width() * 0.5f, 355 - background->Height() * 0.5f);
}


void ThirdStage::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	player->Update(eTime);
}

void ThirdStage::Render()
{
	ZeroIScene::Render();

	background->Render();
	for (auto t : totemList)
	{
		t->Render();
	}
	player->Render();
}

void ThirdStage::CheckOut()
{

}