#include "stdafx.h"
#include "FifthStage.h"

#include "ZeroInputManager.h"

#include "MenuScene.h"


FifthStage::FifthStage()
{
	background = new ZeroSprite("Resource/UI/Background/background.png");
	clearSprite = new ZeroSprite("Resource/UI/Result/clear.png");
	clearSprite->SetColorA(0);
	PushScene(clearSprite);

	dragon = new Dragon();
	player = new PlayerCharacter();
	PushScene(dragon);
	PushScene(player);

	failBackground->SetColorA(0);
	failSprite->SetColorA(0);

	damageText->SetString("Damage : " + to_string((int)player->attackPower));
	healthText->SetString("Health: " + to_string((int)player->health));
	speedText->SetString("Speed: " + to_string((int)player->speed));

	background->SetPos(640 - background->Width() * 0.5f, 355 - background->Height() * 0.5f);
}

void FifthStage::Update(float eTime)
{
	Stage::Update(eTime);

	player->Update(eTime);
	if (dragon->isAlive)
		dragon->Update(eTime);

	CheckOut(eTime);

}

void FifthStage::Render()
{
	Stage::Render();

	background->Render();

	if(dragon->isAlive)
		dragon->Render();
	player->Render();

	damageText->Render();
	healthText->Render();
	speedText->Render();

	clearSprite->Render();
	failBackground->Render();
	failSprite->Render();
}

void FifthStage::ShowWin(float eTime)
{
	static float a = 0;

	if (!dragon->isAlive) {
		a += eTime * 100;
		player->canInput = false;
		if (a <= 255)
			clearSprite->SetColorA((int)a);
		else 
		{
			if (ZeroInputMgr->GetKey(VK_ESCAPE) == INPUTMGR_KEYDOWN)
				ZeroSceneMgr->ChangeScene(new MenuScene());
		}
	}
}

void FifthStage::CheckOut(float eTime)
{
	if (dragon->isAlive)
	{
		dragon->Attack(player, eTime);
		dragon->Damage(player, eTime);
	}

	if (dragon->IsCollision(player) && player->isAttack) {
		dragon->health -= player->attackPower;
		if (!dragon->isAlive)
			PopScene(this);
	}

	ShowResult(player, eTime);
	ShowWin(eTime);

	printf("player health : %.2f\n", player->health);
	printf("dragon health : %.2f\n", dragon->health);
	printf("dragon isAlive : %d\n", dragon->isAlive);
}
