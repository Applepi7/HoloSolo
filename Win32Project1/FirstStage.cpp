#include "stdafx.h"
#include "FirstStage.h"

#include "Random.h"

#include "SecondStage.h"
#include "GameManager.h"

FirstStage::FirstStage() : slimeNum(10)
{
	background = new ZeroSprite("Resource/UI/Background/background.png");
	ui = new UIManager();

	for (int i = 0; i < 10; i++)
	{
		Slime* slime = new Slime();
		slime->SetPos(RandomInt(background->Pos().x + 100, background->Pos().x + background->Width() - 100), RandomInt(background->Pos().y + 100, background->Pos().y + background->Height() - 100));
		slimeList.push_back(slime);
		PushScene(slime);
	}

	player = new PlayerCharacter();
	PushScene(player);

	PushScene(ui);

	failBackground->SetColorA(0);
	failSprite->SetColorA(0);

	damageText->SetString("Damage : " + to_string((int)player->attackPower));
	healthText->SetString("Health: " + to_string((int)player->health));
	speedText->SetString("Speed: " + to_string((int)player->speed));

	background->SetPos(640 - background->Width() * 0.5f, 355 - background->Height() * 0.5f);

}

void FirstStage::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	
	for (auto s : slimeList)
	{
		s->Update(eTime);
		s->Follow(player, s, s->speed, eTime, s->isAlive);
		s->SelfBoom(player, eTime);
		s->Damage(player, eTime);
		if(s->isDamaged)
			ui->EnemyUI(s);

		printf("slime health : %.2f\n", s->health);

	}
	player->Update(eTime);
	item->Update(eTime);
	
	ui->PlayerUI(player);

	CheckOut(eTime);
}

void FirstStage::Render()
{
	background->Render();
	for (auto s : slimeList)
	{
		s->Render();
	}
	player->Render();

	if (slimeNum == 0)
		item->Render();

	damageText->Render();
	healthText->Render();
	speedText->Render();

	ui->healthBar->Render();
	ui->healthFill->Render();
	ui->staminaBar->Render();
	ui->staminaFill->Render();

	for (auto s : slimeList)
	{
		if (s->isDamaged && s->health < 90) 
		{
			ui->enemyHealthBar->Render();
			ui->enemyHealthFill->Render();
		}
	}

	failBackground->Render();
	failSprite->Render();
}

void FirstStage::PopStage()
{
}

void FirstStage::CheckOut(float eTime)
{
	for (auto s = slimeList.begin(); s != slimeList.end();)
	{
		if ((*s)->isPop)
		{
			(*s)->PopScene(*s);
			slimeList.erase(s++);
			slimeNum--;
		}
		s++;
	}

	if (slimeNum == 0) {
		if (IsCollision(player, item)) {
			GameManager::GetInstance()->itemType = item->type;
			PopStage();
			ZeroSceneMgr->ChangeScene(new SecondStage());
		}
	}

	ShowResult(player, eTime);
	printf("player health : %.2f\n", player->health);
}
