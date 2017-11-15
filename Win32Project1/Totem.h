#pragma once
#include "Enemy.h"

#include "ZeroAnimation.h"
#include "ZeroSprite.h"

class Totem :
	public Enemy
{
private:

	pair<float, float> attackTimer;
	pair<float, float> lazerTimer;
	pair<float, float> damageTimer;
	
	int i;
	int totemCondition;

	void Attack(float eTime);

public:
	Totem(int pos);

	ZeroSprite* totemAttack;

	ZeroAnimation* totemIdle;
	ZeroAnimation* lazer;

	int pos;

	bool isAttack;
	bool isAlive;

	void Update(float eTime) override;
	void Render() override;
	
	void Damage(PlayerCharacter* player, float eTime) override;

};

