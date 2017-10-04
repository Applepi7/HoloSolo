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
	
	int totemCondition;

	void Attack(float eTime);

public:
	Totem();
	~Totem();

	ZeroSprite* totemAttack;
	ZeroAnimation* totemIdle;
	ZeroAnimation* lazer;

	void Update(float eTime) override;
	void Render() override;
};

