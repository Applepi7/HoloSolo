#include "stdafx.h"
#include "FourthStage.h"

#include "Random.h"

FourthStage::FourthStage()
{
	background = new ZeroSprite("Resource/UI/Background/background.png");

	golem = new Golem();
	player = new PlayerCharacter();
	PushScene(golem);
	PushScene(player);

	background->SetPos(640 - background->Width() * 0.5f, 355 - background->Height() * 0.5f);
}

void FourthStage::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	player->Update(eTime);
	golem->Update(eTime);

	CheckOut();
	printf("%.2f\n", golem->health);
}

void FourthStage::Render()
{
	ZeroIScene::Render();

	background->Render();

	golem->Render();
	player->Render();
}

void FourthStage::CheckOut()
{
	if (golem->IsCollision(player) && player->isAttack)
		golem->health -= player->attackPower;
}
