#include "stdafx.h"
#include "Wisp.h"


Wisp::Wisp() : wispCondition(MOVE)
{
	wispMove = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		wispMove->PushSprite("Resource/Enemy/Wisp/Move/wisp_move_%d.png", i);
	}

	wispAttack = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 3; i++) {
		for (int i = 1; i <= 3; i++) {
			wispMove->PushSprite("Resource/Enemy/Wisp/Attack/wisp_attack_%d.png", i);
		}
	}

	PushScene(wispMove);
	PushScene(wispAttack);
}

void Wisp::Update(float eTime)
{
	ZeroIScene::Update(eTime);
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

void Wisp::Attack(PlayerCharacter* target)
{
	if (IsOverlapped(target->Pos())) {
		printf("´Ï¾ó±¼\n");
	}
}
