#include "stdafx.h"
#include "Wisp.h"


Wisp::Wisp() : wispCondition(MOVE), attackTimer(0, 1.0f), isAlive(true), speed(40)
{
	enemyType = WISP;
	health = 100;

	wispMove = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		wispMove->PushSprite("Resource/Enemy/Wisp/Move/wisp_move_%d.png", i);
	}

	wispAttack = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 3; i++) {
		wispAttack->PushSprite("Resource/Enemy/Wisp/Attack/wisp_attack_%d.png", i);
	}

	PushScene(wispMove);
	PushScene(wispAttack);
}

void Wisp::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (!isAttack)
		wispCondition = MOVE;
	else
		wispCondition = ATTACK;
}

void Wisp::Render()
{
	ZeroIScene::Render();

	switch (wispCondition) {
	case MOVE:
		wispMove->Render();
		break;
	case ATTACK:
		wispAttack->Render();
		break;
	}
}

void Wisp::Attack(PlayerCharacter* target, float eTime)
{
	attackTimer.first += eTime;
	if (attackTimer.first >= attackTimer.second)
	{
		target->health -= 1;
		attackTimer.first = 0;
		isAttack = false;
	}
}

bool Wisp::IsCollision(PlayerCharacter* player)
{
	if (
		(player->Pos().x - Pos().x <= wispMove->Width()) &&
		(Pos().x - player->Pos().x <= player->playerSidle->Width()) &&
		(Pos().y - player->Pos().y <= player->playerSidle->Height()) &&
		(player->Pos().y - Pos().y <= wispMove->Height())
		)
		return true;
	else
		return false;
}

void Wisp::Damage(PlayerCharacter * player, float eTime)
{
	if (IsCollision(player) && player->isAttack)
	{
		isDamaged = true;
		health -= player->attackPower;
		damagedTimer.first += eTime;
		if (damagedTimer.first >= damagedTimer.second)
			isDamaged = false;
	}

	if (health <= 0) isAlive = false;
}
