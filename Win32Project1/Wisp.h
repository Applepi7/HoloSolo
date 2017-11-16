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

	int speed;

	bool isAttack;
	bool isAlive;

	void Update(float eTime) override;
	void Render() override;
	
	void Attack(PlayerCharacter* target, float eTime);
	
	bool IsCollision(PlayerCharacter* player) override;
	void Damage(PlayerCharacter* player, float eTime) override;

	ZeroAnimation* wispMove;
	ZeroAnimation* wispAttack;
};

