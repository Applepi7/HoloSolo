#include "stdafx.h"
#include "Dragon.h"

#include "Random.h"


Dragon::Dragon() : isAlive(true), isDown(false), dragonCondition(IDLE), attackTimer(0, 3), windTimer(0, .5f), wingTimer(0, 1.0f), thunderTimer(0, 2.0f), fireTimer(0, 2.0f), damageTimer(0, .2f), index(RandomInt(0, 1))
{
	enemyType = DRAGON;
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

	SetPos(640 - dragonIdle->Width() * 0.5f, 355 - dragonIdle->Height());
	dWaveLength->SetPos(-dWaveLength->Width() * 0.2f, 0);
	dBreath->SetPos(-280, 100);
	dThunder->SetPos(Pos().x - dThunder->Width() * 0.8f, 400);
	dFire->SetPos(dFire->Width() * 0.5f + 30, 80);
}

void Dragon::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (health <= 0)
		isAlive = false;
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
		dWaveLength->Render();
		dragonWing->Render();
		break;
	case THUNDER:
		dThunder->Render();
		dragonThunder->Render();
		break;
	case FIRE:
		dragonFire->Render();
		dFire->Render();
		break;
	}
}

void Dragon::Attack(PlayerCharacter* player, float eTime)
{
	attackTimer.first += eTime;
	if (attackTimer.first >= attackTimer.second)
	{
		switch (0)
		{
		case 0:
			dragonCondition = WIND;
			windTimer.first += eTime;
			if (dBreath->IsOverlapped(player->collider))
			{
				static float rot = atan2((Pos().y + 200) - player->Pos().y, (Pos().x + 100) - player->Pos().x);
				player->AddPos(cos(rot), sin(rot) * 150 * eTime);
			}
		    if (windTimer.first >= windTimer.second)
			{
				dragonCondition = IDLE;
				fireTimer.first += eTime;
				if (fireTimer.first >= .5f) {
					dragonCondition = FIRE;
					if (fireTimer.first >= fireTimer.second)
					{
						dragonCondition = IDLE;
						fireTimer.first = 0;
						windTimer.first = 0;
						attackTimer.first = 0;
						index = RandomInt(0, 1);
					}
					if (dFire->IsOverlapped(player->collider))
					{
						damageTimer.first += eTime;
						if (damageTimer.first >= .2f)
						{
							player->health -= 5;
							damageTimer.first = 0;
						}
					}
				}
			}
			break;

		case 1:
			dragonCondition = WING;
			wingTimer.first += eTime;
			if (dWaveLength->IsOverlapped(player->collider))
				isDown = true;

			if (isDown)
			{
				if (dragonCondition != THUNDER) {
					printf("asdfsadfsadfasgsagfa");
					player->AddPosY(800 * eTime);
				}

				damageTimer.first += eTime;
				if(damageTimer.first >= damageTimer.second)
				{
					damageTimer.first = 0;
					isDown = false;
				}
			}

			if (wingTimer.first >= wingTimer.second)
			{
				dragonCondition = IDLE;
				thunderTimer.first += eTime;
				if (thunderTimer.first >= .5f) {
					dragonCondition = THUNDER;
					if (dThunder->IsOverlapped(player->collider))
					{
						damageTimer.first += eTime;
						if (damageTimer.first >= .1)
						{
							player->health -= 4.0f;
							damageTimer.first = 0;
						}
					}
					if (thunderTimer.first >= thunderTimer.second)
					{
						dragonCondition = IDLE;
						thunderTimer.first = 0;
						wingTimer.first = 0;
						attackTimer.first = 0;
						index = RandomInt(0, 1);
					}
				}
			}
			break;
		}
	}
}

void Dragon::Damage(PlayerCharacter* player, float eTime)
{
	if (IsCollision(player) && player->isAttack)
	{
		health -= player->attackPower;
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

bool Dragon::IsCollision(PlayerCharacter* player, ZeroAnimation* anim)
{
	if (
		(player->Pos().x - Pos().x <= anim->Width()) &&
		(Pos().x - player->Pos().x <= player->playerSidle->Width()) &&
		(Pos().y - player->Pos().y <= player->playerSidle->Height()) &&
		(player->Pos().y - Pos().y <= anim->Height())
		)
		return true;
	else
		return false;
}
