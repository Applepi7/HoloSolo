#pragma once
#include "Enemy.h"
#include "PlayerCharacter.h"

#include "ZeroAnimation.h"

class Wisp :
	public Enemy
{
private:
	int wispCondition;

	pair<float, float> attackTimer;

public:
	Wisp();

	float health;
	bool isAttack;
	bool isAlive;

	void Update(float eTime) override;
	void Render() override;
	
	void Attack(PlayerCharacter* target, float eTime);
	bool IsCollision(PlayerCharacter* player) override;

	ZeroAnimation* wispMove;
	ZeroAnimation* wispAttack;
};

