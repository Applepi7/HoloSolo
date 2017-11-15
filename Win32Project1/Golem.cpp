#include "stdafx.h"
#include "Golem.h"

#include "Random.h"

Golem::Golem() : golemCondition(IDLE), attackTimer(0, 3.0f), basicATimer(0, 1.3f), crackATimer(0, 2.0f), isAttack(false), isAlive(true), isShowCrack(false), isDamage(false), index(RandomInt(0, 2))
{
	health = 400;

	golemIdle = new ZeroAnimation(3.5f);
	for (int i = 1; i <= 4; i++) {
		golemIdle->PushSprite("Resource/Enemy/Golem/Idle/golemIdle_%d.png", i);
	}

	golemAttack = new ZeroAnimation(3.5f);
	for (int i = 1; i <= 6; i++) {
		golemAttack->PushSprite("Resource/Enemy/Golem/Attack/Basic/golemAttack_%d.png", i);
	}

	golemCAttack = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 5; i++) {
		golemCAttack->PushSprite("Resource/Enemy/Golem/Attack/Crack/golemCrackAttack_%d.png", i);
	}

	groundCrack = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 3; i++) {
		groundCrack->PushSprite("Resource/Enemy/Golem/Attack/Crack/groundCrack_%d.png", i);
	}

	groundFragmentL = new ZeroSprite("Resource/Enemy/Golem/Attack/Basic/groundFragment.png");
	groundFragmentR = new ZeroSprite("Resource/Enemy/Golem/Attack/Basic/groundFragment.png");


	PushScene(golemIdle);
	PushScene(golemAttack);
	PushScene(golemCAttack);
	PushScene(groundCrack);
	PushScene(groundFragmentL);
	PushScene(groundFragmentR);

	golemAttack->SetScalingCenter(golemAttack->Width() * 0.28f);

	SetPos(640 - golemIdle->Width() * 0.5f, 355 - golemIdle->Height());
	groundCrack->SetPos(Pos().x - 470, Pos().y + 220);
	groundFragmentL->SetPos(Pos().x - groundCrack->Width(), Pos().y + 150);
	groundFragmentR->SetPos(Pos().x - groundFragmentR->Width() * 0.6f, Pos().y + 150);
}

void Golem::Update(float eTime)
{
	ZeroIScene::Update(eTime);

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
		groundFragmentR->Render();
		golemAttack->SetScale(1, 1);
		golemAttack->Render();
		break;
	case LEFTATTACK:
		groundFragmentL->Render();
		golemAttack->SetScale(-1, 1);
		golemAttack->Render();
		break;
	case CRACKATTACK:
		if (isShowCrack)
			groundCrack->Render();
		golemCAttack->Render();
		break;
	}
}

void Golem::Attack(PlayerCharacter* player, float eTime)
{
	attackTimer.first += eTime;
	if (attackTimer.first >= attackTimer.second)
	{
		switch (index)
		{
		case 0:
			golemCondition = RIGHTATTACK;
			SetPos(640 - golemIdle->Width() * 0.5f + 140, 355 - golemIdle->Height());
			basicATimer.first += eTime;
			groundFragmentR->AddPosY(350 * eTime);
			if (groundFragmentR->IsOverlapped(player->collider))
			{
				isDamage = true;
			}
			if (basicATimer.first >= basicATimer.second)
			{
				if (isDamage)
					player->health -= 30;

				SetPos(640 - golemIdle->Width() * 0.5f, 355 - golemIdle->Height());
				groundFragmentR->SetPos(Pos().x - groundFragmentR->Width() * 0.6f, Pos().y + 150);

				golemCondition = IDLE;
				basicATimer.first = 0;
				attackTimer.first = 0;
				index = RandomInt(0, 2);
				isDamage = false;
			}
			break;
		case 1:
			golemCondition = LEFTATTACK;
			SetPos(640 - golemIdle->Width() * 0.5f + 140, 355 - golemIdle->Height() + 10);
			basicATimer.first += eTime;
			groundFragmentL->AddPosY(350 * eTime);
			if (groundFragmentL->IsOverlapped(player->collider))
			{
				isDamage = true;
			}
			if (basicATimer.first >= basicATimer.second)
			{
				if (isDamage)
					player->health -= 30;

				SetPos(640 - golemIdle->Width() * 0.5f, 355 - golemIdle->Height());
				groundFragmentL->SetPos(Pos().x - groundCrack->Width(), Pos().y + 150);

				golemCondition = IDLE;
				basicATimer.first = 0;
				attackTimer.first = 0;
				index = RandomInt(0, 2);
				isDamage = false;
			}
			break;
		case 2:
			golemCondition = CRACKATTACK;
			SetPos(640 - golemIdle->Width() * 0.5f, 355 - golemIdle->Height());
			crackATimer.first += eTime;
			if (crackATimer.first >= 1.0f)
			{
				isShowCrack = true;

				if (groundCrack->IsOverlapped(player->collider))
				{
					isDamage = true;
				}
				if (crackATimer.first >= crackATimer.second)
				{
					if (isDamage)
						player->health -= 60;

					golemCondition = IDLE;
					crackATimer.first = 0;
					attackTimer.first = 0;
					isShowCrack = false;
					isDamage = false;
					index = RandomInt(0, 2);
				}
			}
			break;
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

bool Golem::IsCollision(PlayerCharacter* player, ZeroAnimation* anim)
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

void Golem::Damage(PlayerCharacter * player)
{
	if (IsCollision(player) && player->isAttack)
	{
		health -= player->attackPower;

		if (health <= 0)
		{
			isAlive = false;
		}
	}
}
