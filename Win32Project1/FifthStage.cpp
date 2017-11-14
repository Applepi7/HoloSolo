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

	damageText->SetString("Damage : " + to_string((int)player->attackPower));
	healthText->SetString("Health: " + to_string((int)player->health));
	speedText->SetString("Speed: " + to_string((int)player->speed));
}

void FifthStage::Update(float eTime)
{
	Stage::Update(eTime);

	player->Update(eTime);
	dragon->Update(eTime);

	CheckOut(eTime);

}

void FifthStage::Render()
{
	Stage::Render();

	background->Render();

	dragon->Render();
	player->Render();

	damageText->Render();
	healthText->Render();
	speedText->Render();
}

void FifthStage::CheckOut(float eTime)
{
	if (dragon->isAlive)
	{
		dragon->Attack(player, eTime);
		dragon->Damage(player, eTime);
	}

	if (dragon->IsCollision(player) && player->isAttack)
		dragon->health -= player->attackPower;

	printf("player health : %d\n", player->health);
	printf("dragon health : %.2f\n", dragon->health);
}
