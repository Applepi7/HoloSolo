#include "stdafx.h"
#include "SecondStage.h"

#include "Random.h"


SecondStage::SecondStage()
{
	background = new ZeroSprite("Resource/UI/Background/background.png");

	for (int i = 0; i < 10; i++)
	{
		Wisp* wisp = new Wisp();
		wisp->SetPos(RandomInt(background->Pos().x, background->Pos().x + background->Width()), RandomInt(background->Pos().y, background->Pos().y + background->Height()));
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
		if (player->Pos().x - w->Pos().x <= 100 && player->Pos().y - w->Pos().y <= 100)
			w->Follow(player, w, eTime, w->isAlive);
	}
	player->Update(eTime);

	// CheckOut();
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
}

void SecondStage::CheckOut()
{
	for (auto w = wispList.begin(); w != wispList.end();)
	{
		if (!(*w)->isAlive)
		{
			PopScene(*w);
			wispList.erase(w++);
		}
		w++;
	}
}