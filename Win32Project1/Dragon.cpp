#include "stdafx.h"
#include "Dragon.h"

#include "Random.h"


Dragon::Dragon() : dragonCondition(IDLE), attackTimer(0, 3.0f), windTimer(0, 3.0f), wingTimer(0, 3.0f), thunderTimer(0, 3.0f), fireTimer(0, 3.0f), index(RandomInt(0, 3))
{
	health = 500;

	dragonIdle = new ZeroAnimation(2.5f);
	for (int i = 1; i <= 3; i++)
	{
		dragonIdle->PushSprite("Resource/Enemy/Dragon/Idle/dragonIdle_%d.png", i);
	}

	dragonWing = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 3; i++)
	{
		dragonWing->PushSprite("Resource/Enemy/Dragon/Attack/Wing/dragonWing_%d.png", i);
	}

	dragonThunder = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 3; i++)
	{
		dragonThunder->PushSprite("Resource/Enemy/Dragon/Attack/Thunder/dragonThunder_%d.png", i);
	}

	dragonWind = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 5; i++)
	{
		dragonWind->PushSprite("Resource/Enemy/Dragon/Attack/Wind/dragonWind_%d.png", i);
	}

	dragonFire = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 5; i++)
	{
		dragonFire->PushSprite("Resource/Enemy/Dragon/Attack/Fire/dragonFire_%d.png", i);
	}

	dBreath = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 4; i++)
	{
		dBreath->PushSprite("Resource/Enemy/Dragon/Attack/Wind/dBreath_%d.png", i);
	}
	dThunder = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++)
	{
		dThunder->PushSprite("Resource/Enemy/Dragon/Attack/Thunder/dThunder_%d.png", i);
	}

	dWaveLength = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 3; i++)
	{
		dWaveLength->PushSprite("Resource/Enemy/Dragon/Attack/Wing/dWaveLength_%d.png", i);
	}

	dFire = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 3; i++)
	{
		dFire->PushSprite("Resource/Enemy/Dragon/Attack/Fire/dFire_%d.png", i);
	}

	PushScene(dragonIdle);
	PushScene(dragonWind);
	PushScene(dragonWing);
	PushScene(dragonThunder);
	PushScene(dragonFire);
	PushScene(dBreath);
	PushScene(dThunder);
	PushScene(dWaveLength);
	PushScene(dFire);

	SetPos(640 - dragonIdle->Width() * 0.5f, 355 - dragonIdle->Height() * 0.5f);
	dWaveLength->SetPos(0, 0);
	dThunder->SetPos(50, 50);
}

void Dragon::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	Attack(eTime);
}

void Dragon::Render()
{
	ZeroIScene::Render();

	switch (dragonCondition)
	{
	case IDLE:
		dragonIdle->Render();
		break;
	case WIND:
		dragonWind->Render();
		dBreath->Render();
		break;
	case WING:
		dragonWing->Render();
		dWaveLength->Render();
		break;
	case THUNDER:
		dragonThunder->Render();
		dThunder->Render();
		break;
	case FIRE:
		dragonFire->Render();
		dFire->Render();
		break;
	}
}

void Dragon::Attack(float eTime)
{
	attackTimer.first += eTime;
	if (attackTimer.first >= attackTimer.second)
	{
		switch (index)
		{
		case 0:
			dragonCondition = THUNDER;
			thunderTimer.first += eTime;
			if (thunderTimer.first >= thunderTimer.second)
			{
				dragonCondition = IDLE;
				thunderTimer.first = 0;
				attackTimer.first = 0;
				index = RandomInt(0, 3);
			}
			break;
		case 1:
			dragonCondition = WIND;
			windTimer.first += eTime;
			if (windTimer.first >= windTimer.second)
			{
				dragonCondition = IDLE;
				windTimer.first = 0;
				attackTimer.first = 0;
				index = RandomInt(0, 3);
			}
			break;
		case 2:
			dragonCondition = WING;
			wingTimer.first += eTime;
			if (wingTimer.first >= wingTimer.second)
			{
				dragonCondition = IDLE;
				wingTimer.first = 0;
				attackTimer.first = 0;
				index = RandomInt(0, 3);
			}
			break;
		case 3:
			dragonCondition = FIRE;
			fireTimer.first += eTime;
			if (fireTimer.first >= fireTimer.second)
			{
				dragonCondition = IDLE;
				fireTimer.first = 0;
				attackTimer.first = 0;
				index = RandomInt(0, 3);
			}
		}


	}
}

bool Dragon::IsCollision(PlayerCharacter * player)
{
	if (
		(player->Pos().x - Pos().x <= dragonIdle->Width()) &&
		(Pos().x - player->Pos().x <= player->playerSidle->Width()) &&
		(Pos().y - player->Pos().y <= player->playerSidle->Height()) &&
		(player->Pos().y - Pos().y <= dragonIdle->Height())
		)
		return true;
	else
		return false;
}
