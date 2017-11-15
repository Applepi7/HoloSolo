#include "stdafx.h"
#include "Totem.h"


Totem::Totem(int pos) : totemCondition(IDLE), attackTimer(0, 3), lazerTimer(0, 1), damageTimer(0, .1f), isAttack(false), isAlive(true), i(1)
									// attackTimer : 5초동안 가만히 있다가
									// lazerTimer : 1초동안 레이저 파바ㅏㅏ바ㅏ박
{
	health = 150;

	totemAttack = new ZeroSprite("Resource/Enemy/Totem/Attack/totem_attack.png");
	
	totemIdle = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		totemIdle->PushSprite("Resource/Enemy/Totem/Idle/totem_idle_%d.png", i);
	}

	lazer = new ZeroAnimation(7.0f);
	for (int i = 1; i <= 4; i++) {
		lazer->PushSprite("Resource/Enemy/Totem/Lazer/lazer_%d.png", i);
	}

	if (pos % 2 == 0)
	{
		totemIdle->SetScalingCenter(totemIdle->Width() * .5f);
		totemAttack->SetScalingCenter(totemIdle->Width() * .5f);
		lazer->SetScalingCenter(lazer->Width() * .5f);

		totemIdle->SetScale(-1, 1);
		totemAttack->SetScale(-1, 1);
		lazer->SetScale(-0.9, 0.9);
		lazer->SetPosX(-totemAttack->Width() + 100);
	}
	else
	{
		lazer->SetPosX(totemAttack->Width() - 50);
		lazer->SetScale(0.9, 0.9);
	}


	PushScene(totemAttack);
	PushScene(totemIdle);
	PushScene(lazer);

	lazer->SetScalingCenter(1, lazer->Height() * 2.0f);
	
	this->pos = pos % 2;

}

void Totem::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	Attack(eTime);

	if (health <= 0)
		isAlive = false;

}

void Totem::Render()
{
	ZeroIScene::Render();

	switch (totemCondition)
	{
	case IDLE:
		totemIdle->Render();
		break;
	case ATTACK:
		lazer->Render();
		totemAttack->Render();
		break;
	}

}

void Totem::Damage(PlayerCharacter * player, float eTime)
{
	if (lazer->IsOverlapped(player->collider) && isAttack)
	{
		damageTimer.first += eTime;
		if (damageTimer.first >= damageTimer.second)
		{
			player->health -= 1;
			damageTimer.first = 0;
		}
	}

	else if ((totemIdle->IsOverlapped(player->collider) || totemAttack->IsOverlapped(player->collider)) && player->isAttack)
		health -= player->attackPower;
}

void Totem::Attack(float eTime)
{
	attackTimer.first += eTime;
	if (attackTimer.first >= attackTimer.second)
	{
		isAttack = true;
		lazerTimer.first += eTime;

		switch (i)
		{
		case 0:
			if(pos == 0)
				totemCondition = ATTACK;
			if (lazerTimer.first >= lazerTimer.second)
			{
				isAttack = false;
				lazerTimer.first = 0;
				attackTimer.first = 0;
				totemCondition = IDLE;
				i = 1;
			}
		break;
		case 1:
			if(pos == 1)
				totemCondition = ATTACK;

			if (lazerTimer.first >= lazerTimer.second)
			{
				isAttack = false;
				lazerTimer.first = 0;
				attackTimer.first = 0;
				totemCondition = IDLE;
				i = 0;
			}

		}
	}
}