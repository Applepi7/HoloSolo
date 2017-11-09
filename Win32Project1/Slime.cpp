#include "stdafx.h"
#include "Slime.h"


Slime::Slime() : slimeCondition(MOVE), boomDistance(100), speed(150), health(90), isAlive(true), isPop(false), boomTimer(0, 2), popTimer(0, .5f)
{
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
	if (target->Pos().x - Pos().x <= boomDistance && target->Pos().y - Pos().y <= boomDistance) {
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
			isPop = true;
		}
	}
}
