#include "stdafx.h"
#include "Golem.h"

#include "Random.h"

Golem::Golem() : golemCondition(IDLE), attackTimer(0, 3.0f), basicATimer(0, 2.0f), crackATimer(0, 1.0f), isAttack(false), isAlive(true), index(RandomInt(0, 2))
{
	health = 400;

	golemIdle = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 4; i++) {
		golemIdle->PushSprite("Resource/Enemy/Golem/Idle/golemIdle_%d.png", i);
	}

	golemAttack = new ZeroAnimation(6.0f);
	for (int i = 1; i <= 6; i++) {
		golemAttack->PushSprite("Resource/Enemy/Golem/Attack/Basic/golemAttack_%d.png", i);
	} 

	golemCAttack = new ZeroAnimation(5.0f);	
	for (int i = 1; i <= 5; i++) {
		golemCAttack->PushSprite("Resource/Enemy/Golem/Attack/Crack/golemCrackAttack_%d.png", i);
	}

	groundCrack = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 3; i++) {
		groundCrack->PushSprite("Resource/Enemy/Golem/Attack/Crack/groundCrack_%d.png", i);
	}

	groundFragment = new ZeroSprite("Resource/Enemy/Golem/Attack/Basic/groundFragment.png");

	PushScene(golemIdle);
	PushScene(golemAttack);
	PushScene(golemCAttack);
	PushScene(groundCrack);
	PushScene(groundFragment);

	golemAttack->SetScalingCenter(golemAttack->Width() * 0.28f);

	SetPos(640 - golemIdle->Width() * 0.5f, 355 - golemIdle->Height() * 0.5f - 50);
	groundCrack->SetPos(Pos().x - groundCrack->Width(), Pos().y + 100);
}


void Golem::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	Attack(eTime, isAlive);
}

void Golem::Render()
{
	ZeroIScene::Render();

	switch (golemCondition)
	{
	case IDLE:
		golemIdle->Render();
		break;
	case RIGHTATTACK:
		golemAttack->SetScale(1, 1);
		golemAttack->Render();
		groundFragment->Render();
		break;
	case LEFTATTACK:
		groundFragment->Render();
			golemAttack->SetScale(-1, 1);
		golemAttack->Render();
		break;
	case CRACKATTACK:
		groundCrack->Render();
		golemCAttack->Render();
		break;
	}
}

void Golem::Attack(float eTime, bool isAttack)
{
	attackTimer.first += eTime;

	if(isAttack){
		if (attackTimer.first >= attackTimer.second)
		{
			switch (index)
			{
			case 0:
				golemCondition = RIGHTATTACK;
				SetPos(640 - golemIdle->Width() * 0.5f + 140, 355 - golemIdle->Height() * 0.5f - 40);
				basicATimer.first += eTime;
				if (basicATimer.first >= basicATimer.second)
				{
					SetPos(640 - golemIdle->Width() * 0.5f, 355 - golemIdle->Height() * 0.5f - 50);
					golemCondition = IDLE;
					basicATimer.first = 0;
					attackTimer.first = 0;
					index = RandomInt(0, 2);
				}
				break;
			case 1:
				golemCondition = LEFTATTACK;
				SetPos(640 - golemIdle->Width() * 0.5f + 140, 355 - golemIdle->Height() * 0.5f - 40);
				basicATimer.first += eTime;
				if (basicATimer.first >= basicATimer.second)
				{
					SetPos(640 - golemIdle->Width() * 0.5f, 355 - golemIdle->Height() * 0.5f - 50);
					golemCondition = IDLE;
					basicATimer.first = 0;
					attackTimer.first = 0;
					index = RandomInt(0, 2);
				}
				break;
			case 2:
				golemCondition = CRACKATTACK;
				SetPos(640 - golemIdle->Width() * 0.5f, 355 - golemIdle->Height() * 0.5f - 50);
				basicATimer.first += eTime;
				if (basicATimer.first >= basicATimer.second)
				{
					golemCondition = IDLE;
					basicATimer.first = 0;
					attackTimer.first = 0;
					index = RandomInt(0, 2);
				}
				break;
			}
		}
	}
}

bool Golem::IsCollision(PlayerCharacter * player)
{
	if (
		(player->Pos().x - Pos().x <= golemIdle->Width()) &&
		(Pos().x - player->Pos().x <= player->playerSidle->Width()) &&
		(Pos().y - player->Pos().y <= player->playerSidle->Height()) &&
		(player->Pos().y - Pos().y <= golemIdle->Height())
		)
		return true;
	else
		return false;
}

void Golem::Damage(PlayerCharacter * player)
{
	if (IsCollision(player) && player->isAttack) {
		health -= player->attackPower;

		if (health <= 0) {
			isAlive = false;
		}
	}
}
