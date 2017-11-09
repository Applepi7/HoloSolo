#include "stdafx.h"
#include "FirstStage.h"

#include "Random.h"

FirstStage::FirstStage()
{
	background = new ZeroSprite("Resource/UI/Background/background.png");

	for (int i = 0; i < 10; i++)
	{
		Slime* slime = new Slime();
		slime->SetPos(RandomInt(background->Pos().x, background->Pos().x + background->Width()), RandomInt(background->Pos().y, background->Pos().y + background->Height()));
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

	CheckOut();
}

void FirstStage::Render()
{
	background->Render();
	for (auto s : slimeList)
	{
		s->Render();
	}
	player->Render();
}

void FirstStage::CheckOut()
{
	for (auto s = slimeList.begin(); s != slimeList.end();)
	{
		if ((*s)->isPop) 
		{
			(*s)->PopScene(*s);
			slimeList.erase(s++);
		}
		s++;
	}
}
