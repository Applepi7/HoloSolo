#include "stdafx.h"
#include "SecondStage.h"

#include "Random.h"

#include "ThirdStage.h"
#include "GameManager.h"

SecondStage::SecondStage() : damageTimer(0, .25f), wispNum(10)
{
	ui = new UIManager();

	background = new ZeroSprite("Resource/UI/Background/background.png");

	for (int i = 0; i < 10; i++)
	{
		Wisp* wisp = new Wisp();
		wisp->SetPos(RandomInt(background->Pos().x + 130, background->Pos().x + background->Width() - 130), RandomInt(background->Pos().y + 130, background->Pos().y + background->Height() - 130));
		wispList.push_back(wisp);
		PushScene(wisp);
	}

	player = new PlayerCharacter();
	PushScene(player);

	failBackground->SetColorA(0);
	failSprite->SetColorA(0);

	damageText->SetString("Damage : " + to_string((int)player->attackPower));
	healthText->SetString("Health: " + to_string((int)player->health));
	speedText->SetString("Speed : " + to_string((int)player->speed));

	background->SetPos(640 - background->Width() * 0.5f, 355 - background->Height() * 0.5f);
}

void SecondStage::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	for (auto w : wispList)
	{
		w->Update(eTime);
		w->Follow(player, w, w->speed, eTime, w->isAlive);
		if (w->IsCollision(player)) {
			w->Attack(player, eTime);
		}

		printf("wisp health : %.2f\n", w->health);
	}
	item->Update(eTime);
	player->Update(eTime);

	if (player->health >= 0) {
		switch (player->defaultHealth)
		{
		case 100:
			ui->healthFill->SetScale(player->health * 0.01, 1);
			break;
		case 125:
			ui->healthFill->SetScale(player->health * 0.008, 1);
			break;
		case 150:
			ui->healthFill->SetScale(player->health * 0.0067, 1);
			break;
		}
	}
	else
		ui->healthFill->SetScale(0, 1);

	ui->staminaFill->SetScale(player->stamina * 0.01, 1);


	CheckOut(eTime);

	printf("%d\n", player->health);
}

void SecondStage::Render()
{
	ZeroIScene::Render();

	background->Render();

	for (auto w : wispList)
	{
		w->Render();
	}player->Render();
	

	if (wispNum == 0)
		item->Render();


	damageText->Render();
	healthText->Render();
	speedText->Render();

	ui->healthBar->Render();
	ui->healthFill->Render();
	ui->staminaBar->Render();
	ui->staminaFill->Render();

	failBackground->Render();
	failSprite->Render();
}

void SecondStage::PopStage()
{
}

void SecondStage::CheckOut(float eTime)
{
	for (auto w = wispList.begin(); w != wispList.end();)
	{
		
		(*w)->Damage(player);

		if (!(*w)->isAlive)
		{
			wispNum--;
			PopScene(*w);
			wispList.erase(w++);
		}
		w++;
	}

	if (wispNum == 0) {
		if (IsCollision(player, item)) {
			//GameManager::GetInstance()->itemType = item->type;
			PopStage();
			ZeroSceneMgr->ChangeScene(new ThirdStage()); 
		}
	}

	ShowResult(player, eTime);
	printf("player health : %.2f", player->health);
}