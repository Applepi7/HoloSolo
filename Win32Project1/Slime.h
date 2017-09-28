#pragma once

#include "ZeroAnimation.h"
#include "ZeroSprite.h"

#include "Enemy.h"
#include "PlayerCharacter.h"

class Slime :
	public Enemy
{
private:
	int boomDistance;
	int slimeCondition;

	pair<float, float> boomTimer;
	pair<float, float> popTimer;

public:
	Slime();
	~Slime();

	enum CONDITION {
		MOVE,
		BOOM
	};

	int speed;
	int health;

	bool isAlive;

	ZeroAnimation* slimeMove;
	ZeroAnimation* slimeBoom;

	void Update(float eTime) override;
	void Render() override;

	void SelfBoom(PlayerCharacter* target, float eTime);
};

