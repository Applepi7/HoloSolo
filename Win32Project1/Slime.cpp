#include "stdafx.h"
#include "Slime.h"


Slime::Slime() : slimeCondition(MOVE), boomDistance(150), speed(150), isAlive(true), boomTimer(0, 2), popTimer(0, .5f)
{
	slimeMove = new ZeroAnimation(1.5f);
	for (int i = 1; i <= 3; i++) {
		slimeMove->PushSprite("Resource/Enemy/Slime/Move/slime_front_%d.png", i);
	}
	PushScene(slimeMove);

	slimeBoom = new ZeroAnimation(1.5f);
	for (int i = 1; i <= 3; i++) {
		slimeBoom->PushSprite("Resource/Enemy/Slime/Boom/slime_boom_%d.png", i);
	}
	PushScene(slimeBoom);
}


Slime::~Slime()
{
}

void Slime::Update(float eTime)
{
	ZeroIScene::Update(eTime);

}

void Slime::Render()
{
	ZeroIScene::Render();

	switch (slimeCondition) {
	case MOVE:
		slimeMove->Render();
		break;
	case BOOM:
		slimeBoom->Render();
		break;
	}
}

void Slime::SelfBoom(PlayerCharacter * target, float eTime)
{
	if (target->Pos().x - Pos().x <= boomDistance && target->Pos().y - Pos().y <= boomDistance) {
		boomTimer.first += eTime;
		if (boomTimer.first >= boomTimer.second) {
			slimeCondition = BOOM;
			isAlive = false;
		}
	}
	if (!isAlive) {
		popTimer.first += eTime;
		if (popTimer.first >= popTimer.second) {
			PopScene(slimeMove);
			PopScene(slimeBoom);	// 추후 수정
		}
	}
}
