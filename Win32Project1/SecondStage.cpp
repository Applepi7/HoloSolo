#include "stdafx.h"
#include "SecondStage.h"

#include "Random.h"

#include "ThirdStage.h"

SecondStage::SecondStage() : damageTimer(0, .25f), wispNum(10)
{
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

	background->SetPos(640 - background->Width() * 0.5f, 355 - background->Height() * 0.5f);
}

void SecondStage::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	for (auto w : wispList)
	{
		w->Update(eTime);
		w->Follow(player, w, w->speed, eTime, w->isAlive);

		printf("%.2f\n", w->health);
	}
	item->Update(eTime);
	player->Update(eTime);

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
	}

	if (wispNum == 0)
		item->Render();

	player->Render();
}

void SecondStage::PopStage()
{
	PopScene(player);
}

void SecondStage::CheckOut(float eTime)
{
	for (auto w = wispList.begin(); w != wispList.end();)
	{
		if ((*w)->IsCollision(player)) {
			(*w)->Attack(player, eTime);
		}
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
		if (item->IsCollision(player)) {
			item->GiveAbility(player);
			PopStage();
			ZeroSceneMgr->ChangeScene(new ThirdStage());
		}
	}
}