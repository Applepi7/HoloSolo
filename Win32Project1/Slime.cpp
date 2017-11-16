#include "stdafx.h"
#include "Slime.h"



Slime::Slime() : slimeCondition(MOVE), boomDistance(100), speed(25), isAlive(true), isPop(false), boomTimer(0, 1.7f), popTimer(0, .5f)
{
	health = 90;
	enemyType = SLIME;

	ZeroSoundMgr->PushSound("Resource/Sound/Slime/Slime_death.wav", "boomSound");
	ZeroSoundMgr->PushSound("Resource/Sound/Slime/Slime_ill.wav", "damageSound");
	ZeroSoundMgr->PushSound("Resource/Sound/Slime/Slime_walk.wav", "moveSound");

	ZeroSoundMgr->PushChannel("boomSound", "BoomChannel", true);
	ZeroSoundMgr->PushChannel("damageSound", "DamageChannel", true);
	ZeroSoundMgr->PushChannel("moveSound", "MoveChannel", true);

	slimeMove = new ZeroAnimation(1.5f);
	for (int i = 1; i <= 3; i++) {
		slimeMove->PushSprite("Resource/Enemy/Slime/Move/slime_front_%d.png", i);
	}

	slimeBoom = new ZeroAnimation(1.5f);
	for (int i = 1; i <= 3; i++) {
		slimeBoom->PushSprite("Resource/Enemy/Slime/Boom/slime_boom_%d.png", i);
	}
	
	PushScene(slimeMove);
	PushScene(slimeBoom);
}


void Slime::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	PlayMoveSound();
}

void Slime::Render()
{
	ZeroIScene::Render();

	switch (slimeCondition) {
	case MOVE:
		slimeMove->Render();
		break;
	case ATTACK:
		slimeBoom->Render();
		break;
	}
}

void Slime::SelfBoom(PlayerCharacter * target, float eTime)
{
	if (abs(target->Pos().x - Pos().x) <= boomDistance && abs(target->Pos().y - Pos().y) <= boomDistance) {
		boomTimer.first += eTime;
		if (boomTimer.first >= boomTimer.second) {
			slimeCondition = ATTACK;
			isAlive = false;
		}
	}
	if (!isAlive) {
		popTimer.first += eTime;
		if (popTimer.first >= popTimer.second) {
			PopScene(slimeMove);
			PopScene(slimeBoom);
			target->health -= 20;
			ZeroSoundMgr->PlayChannel("BoomChannel");
			isPop = true;
		}
	}
}

bool Slime::IsCollision(PlayerCharacter * player)
{
	if (
		(player->Pos().x - Pos().x <= slimeMove->Width()) &&
		(Pos().x - player->Pos().x <= player->playerSidle->Width()) &&
		(Pos().y - player->Pos().y <= player->playerSidle->Height()) &&
		(player->Pos().y - Pos().y <= slimeMove->Height())
		)
		return true;
	else
		return false;
}

void Slime::Damage(PlayerCharacter* player, float eTime)
{
	if (IsCollision(player) && player->isAttack)
	{
		ZeroSoundMgr->PlayChannel("DamageChannel");
		isDamaged = true;
		health -= player->attackPower;
		damagedTimer.first += eTime;
		if (damagedTimer.first >= damagedTimer.second)
		{
			isDamaged = false;
		}
	}

	if (health <= 0) isPop = true;
}

void Slime::PlayMoveSound()
{
	static int i = 0;
	if (i != 0) {
		i++;
		ZeroSoundMgr->PlayChannel("MoveChannel");
	}
}