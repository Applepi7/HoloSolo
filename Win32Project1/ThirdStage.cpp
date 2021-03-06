#include "stdafx.h"
#include "ThirdStage.h"

#include "Random.h"

#include "FourthStage.h"

ThirdStage::ThirdStage() : totemNum(5)
{
	background = new ZeroSprite("Resource/UI/Background/background.png");
	ui = new UIManager();

	for (int i = 1; i <= 5; i++)
	{
		Totem* totem = new Totem(i);
		if (i % 2 == 1) {
			totem->SetPos(background->Pos().x + 100, background->Pos().y + 85 * i);
		}
		else {
			totem->SetPos(background->Pos().x + background->Width() - 100, background->Pos().y + 85 * i);
		}

		totemList.push_back(totem);
		PushScene(totem);
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


void ThirdStage::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	for (auto t : totemList)
	{
		if(t->isDamaged)
			ui->EnemyUI(t);
	}

	item->Update(eTime);
	player->Update(eTime);

	ui->PlayerUI(player);

	CheckOut(eTime);
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

	if (totemNum == 0)
		item->Render();

	damageText->Render();
	healthText->Render();
	speedText->Render();

	for (auto t : totemList)
	{
		if (t->isDamaged && t->health < 150)
		{
			ui->enemyHealthBar->Render();
			ui->enemyHealthFill->Render();
		}
	}

	ui->healthBar->Render();
	ui->healthFill->Render();
	ui->staminaBar->Render();
	ui->staminaFill->Render();

	failBackground->Render();
	failSprite->Render();
}

void ThirdStage::PopStage()
{
}

void ThirdStage::CheckOut(float eTime)
{
	for (auto t : totemList)
	{
		t->Damage(player, eTime);
		printf("totem health : %.2f\n", t->health);
	}

	for (auto t = totemList.begin(); t != totemList.end();)
	{
		if (!(*t)->isAlive) {
			totemNum--;
			PopScene((*t));
			totemList.erase(t++);
		}
		t++;
	}

	if (totemNum == 0) {
		if (IsCollision(player, item)) {
			PopStage();
			GameManager::GetInstance()->itemType = item->type;
			ZeroSceneMgr->ChangeScene(new FourthStage());
		}
	}

	ShowResult(player, eTime);

	printf("player health : %.2f", player->health);
	printf("%d\n", GameManager::GetInstance()->itemType);
}