#include "stdafx.h"
#include "Totem.h"


Totem::Totem() : totemCondition(2), attackTimer(0, 5), lazerTimer(0, 1)
									// attackTimer : 5초동안 가만히 있다가
									// lazerTimer : 1초동안 레이저 파바ㅏㅏ바ㅏ박
{
	totemAttack = new ZeroSprite("Resource/Enemy/Totem/Attack/totem_attack.png");
	
	totemIdle = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		totemIdle->PushSprite("Resource/Enemy/Totem/Idle/totem_idle_%d.png", i);
	}

	lazer = new ZeroAnimation(7.0f);
	for (int i = 1; i <= 4; i++) {
		lazer->PushSprite("Resource/Enemy/Totem/Lazer/lazer_%d.png", i);
	}
	
	PushScene(totemAttack);
	PushScene(totemIdle);
	PushScene(lazer);

	SetPos(100, 200);
	lazer->SetPosX(totemAttack->Width() - 50);
	lazer->SetScalingCenter(1, lazer->Height() * 2.0f);
	lazer->SetScale(0.9, 0.9);
	
}


Totem::~Totem()
{
}

void Totem::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	Attack(eTime);
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

void Totem::Attack(float eTime)
{
	attackTimer.first += eTime;
	if (attackTimer.first >= attackTimer.second) {
		totemCondition = ATTACK;
		lazerTimer.first += eTime;
		if (lazerTimer.first >= lazerTimer.second) {
			lazerTimer.first = 0;
			attackTimer.first = 0;
			totemCondition = IDLE;
		}
	}
}