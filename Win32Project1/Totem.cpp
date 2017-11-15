#include "stdafx.h"
#include "Totem.h"


Totem::Totem(int pos) : totemCondition(IDLE), attackTimer(0, 3), lazerTimer(0, 1), damageTimer(0, .1f), isAttack(false), isAlive(true), i(1)
									// attackTimer : 5�ʵ��� ������ �ִٰ�
									// lazerTimer : 1�ʵ��� ������ �Ĺ٤����٤���
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
	else {
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

	if (health <= 0) isAlive = false;

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
	if (IsCollision(player) && isAttack)
	{
		damageTimer.first += eTime;
		if (damageTimer.first >= damageTimer.second)
		{
			player->health -= 1;
			damageTimer.first = 0;
		}
	}

	else if (IsCollision(player, totemIdle) && player->isAttack)
		health -= player->attackPower;
}

bool Totem::IsCollision(PlayerCharacter* player)
{
	if (
		(player->Pos().x - lazer->Pos().x <= lazer->Width()) &&
		(Pos().x - player->Pos().x <= player->playerSidle->Width()) &&
		(Pos().y - player->Pos().y <= player->playerSidle->Height()) &&
		(player->Pos().y - lazer->Pos().y <= lazer->Height())
		)
		return true;
	else
		return false;
}

bool Totem::IsCollision(PlayerCharacter* player, ZeroAnimation* anim)
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

void Totem::Attack(float eTime)
{
	printf("%d\n", i);

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