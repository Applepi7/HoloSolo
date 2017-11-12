#include "stdafx.h"
#include "FirstStage.h"

#include "Random.h"

#include "SecondStage.h"

FirstStage::FirstStage() : slimeNum(10)
{
	background = new ZeroSprite("Resource/UI/Background/background.png");

	for (int i = 0; i < 10; i++)
	{
		Slime* slime = new Slime();
		slime->SetPos(RandomInt(background->Pos().x + 100, background->Pos().x + background->Width()), RandomInt(background->Pos().y + 100, background->Pos().y + background->Height()));
		slimeList.push_back(slime);
		PushScene(slime);
	}

	player = new PlayerCharacter();
	PushScene(player);

	background->SetPos(640 - background->Width() * 0.5f, 355 - background->Height() * 0.5f);

}

void FirstStage::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	
	for (auto s : slimeList)
	{
		s->Update(eTime);
		if (player->Pos().x - s->Pos().x <= 100 && player->Pos().y - s->Pos().y <= 100)
			s->Follow(player, s, eTime, s->isAlive);
		s->SelfBoom(player, eTime);

	}
	player->Update(eTime);
	item->Update(eTime);

	CheckOut();
	// SpawnItem();

	printf("%d\n", slimeNum);
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
}

void FirstStage::PopStage()
{
}

void FirstStage::SpawnItem()
{
	PopScene(player);
}

void FirstStage::CheckOut()
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
		if (item->IsCollision(player)) {
			PopStage();
			ZeroSceneMgr->ChangeScene(new SecondStage());
		}
	}
}
