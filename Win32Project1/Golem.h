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

	bool isShowCrack;
	bool isDamage;

	int index;

	pair<float, float> attackTimer;
	pair<float, float> basicATimer;
	pair<float, float> crackATimer;

	GolemCondition golemCondition;

public:
	Golem();

	bool isAlive;
	bool isAttack;

	void Update(float eTime) override;
	void Render() override;
	
	void Attack(PlayerCharacter* player, float eTime);

	bool IsCollision(PlayerCharacter* player) override;
	bool IsCollision(PlayerCharacter* player, ZeroAnimation* anim);
	void Damage(PlayerCharacter* player) override;

	ZeroAnimation* golemIdle;
	ZeroAnimation* golemAttack;
	ZeroAnimation* golemCAttack;

	ZeroAnimation* groundCrack;

	ZeroSprite* groundFragmentL;
	ZeroSprite* groundFragmentR;
};

