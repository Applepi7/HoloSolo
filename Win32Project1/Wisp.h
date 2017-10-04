#pragma once
#include "Enemy.h"
#include "PlayerCharacter.h"

#include "ZeroAnimation.h"

class Wisp :
	public Enemy
{
private:
	int wispCondition;

public:
	Wisp();

	void Update(float eTime) override;
	void Render() override;
	
	void Attack(PlayerCharacter* target);

	ZeroAnimation* wispMove;
	ZeroAnimation* wispAttack;
};

