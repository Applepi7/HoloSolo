#include "stdafx.h"
#include "FourthStage.h"

#include "Random.h"

#include "FifthStage.h"


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

	item->Update(eTime);
	player->Update(eTime);
	if (golem->isAlive)
		golem->Update(eTime);

	CheckOut();
}

void FourthStage::Render()
{
	ZeroIScene::Render();

	background->Render();

	if(golem->isAlive)
		golem->Render();

	player->Render();

	if (!golem->isAlive)
		item->Render();
}

void FourthStage::PopStage()
{
	PopScene(player);
}

void FourthStage::CheckOut()
{
	golem->Damage(player);
	if (!golem->isAlive && item->IsCollision(player)) {
		PopStage();
		ZeroSceneMgr->ChangeScene(new FifthStage());
	}
}
