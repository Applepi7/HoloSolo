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
		
	void PlayMoveSound();

public:
	Slime();

	enum CONDITION {
		MOVE,
		ATTACK
	};

	int speed;

	bool isAlive;
	bool isPop;

	ZeroAnimation* slimeMove;
	ZeroAnimation* slimeBoom;

	void Update(float eTime) override;
	void Render() override;

	void SelfBoom(PlayerCharacter* target, float eTime);

	bool IsCollision(PlayerCharacter* player) override;
	void Damage(PlayerCharacter* player, float eTime) override;
};

