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

	damageText->SetString("Damage : " + to_string((int)player->attackPower));
	healthText->SetString("Health: " + to_string((int)player->health));
	speedText->SetString("Speed : " + to_string((int)player->speed));

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
	else
		item->Render();

	player->Render();

	damageText->Render();
	healthText->Render();
	speedText->Render();
}

void FourthStage::PopStage()
{
}

void FourthStage::CheckOut()
{
	golem->Damage(player);
	/*if (!golem->isAlive && item->IsCollision(player)) {
		PopStage();
		ZeroSceneMgr->ChangeScene(new FifthStage());
	}*/
}
