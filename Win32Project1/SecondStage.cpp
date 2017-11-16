#include "stdafx.h"
#include "SecondStage.h"

#include "Random.h"

#include "ThirdStage.h"
#include "GameManager.h"

SecondStage::SecondStage() : damageTimer(0, .25f), wispNum(10)
{
	background = new ZeroSprite("Resource/UI/Background/background.png");
	ui = new UIManager();

	for (int i = 0; i < 10; i++)
	{
		Wisp* wisp = new Wisp();
		wisp->SetPos(RandomInt(background->Pos().x + 130, background->Pos().x + background->Width() - 130), RandomInt(background->Pos().y + 130, background->Pos().y + background->Height() - 130));
		wispList.push_back(wisp);
		PushScene(wisp);
	}

	player = new PlayerCharacter();
	PushScene(player);

	PushScene(ui);

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
		if (w->isDamaged)
			ui->EnemyUI(w);

	}
	item->Update(eTime);
	player->Update(eTime);

	ui->PlayerUI(player);

	CheckOut(eTime);

	printf("player stamina : %.2f\n", player->stamina);
	printf("%d\n", GameManager::GetInstance()->itemType);
}

void SecondStage::Render()
{
	ZeroIScene::Render();

	background->Render();

	for (auto w : wispList)
	{
		w->Render();
	}
	player->Render();

	if (wispNum == 0)
		item->Render();


	damageText->Render();
	healthText->Render();
	speedText->Render();

	ui->healthBar->Render();
	ui->healthFill->Render();
	ui->staminaBar->Render();
	ui->staminaFill->Render();

	for (auto w : wispList)
	{
		if (w->isDamaged && w->health < 100)
		{
			ui->enemyHealthBar->Render();
			ui->enemyHealthFill->Render();
		}
	}

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
		
		(*w)->Damage(player, eTime);

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
			GameManager::GetInstance()->itemType = item->type;
			PopStage();
			ZeroSceneMgr->ChangeScene(new ThirdStage()); 
		}
	}

	ShowResult(player, eTime);
	printf("player health : %.2f\n", player->health);
}