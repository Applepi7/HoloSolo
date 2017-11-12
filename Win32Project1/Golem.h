#pragma once
#include "Enemy.h"
#include "ZeroSprite.h"

class Golem :
	public Enemy
{
private:
	enum GolemCondition 
	{
		IDLE,
		RIGHTATTACK,
		LEFTATTACK,
		CRACKATTACK
	};

	bool isAttack;
	int index;

	pair<float, float> attackTimer;
	pair<float, float> basicATimer;
	pair<float, float> crackATimer;

	GolemCondition golemCondition;

public:
	Golem();

	bool isAlive;

	void Update(float eTime) override;
	void Render() override;
	
	void Attack(float eTime, bool isAttack);

	bool IsCollision(PlayerCharacter* player) override;
	void Damage(PlayerCharacter* player) override;

	ZeroAnimation* golemIdle;
	ZeroAnimation* golemAttack;
	ZeroAnimation* golemCAttack;

	ZeroAnimation* groundCrack;

	ZeroSprite* groundFragment;
};

