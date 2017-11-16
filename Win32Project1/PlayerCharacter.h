#pragma once
#include "ZeroIScene.h"
#include "ZeroAnimation.h"

#include "Item.h"

class PlayerCharacter :
	public ZeroIScene
{
private:

	pair<float, float> rollTimer;
	pair<float, float> attackTimer;
	pair<float, float> alphaTimer;

	bool isMove;
	bool isRoll;
	bool isKeydown;
	bool canAttack;

	int playerCondition;
	int prevKey;
	int defaultSpeed;
	int defaultDamage;

	void Move(float eTime);
	void Attack(float eTime);
	void Idle();


public:
	PlayerCharacter();

	bool isAttack;

	enum CONDITION {
		RIGHTRUN,
		LEFTRUN,
		UPRUN,
		DOWNRUN,
		RIGHTIDLE,
		LEFTIDLE,
		UPIDLE,
		DOWNIDLE,
		RIGHTROLL,
		LEFTROLL,
		UPROLL,
		DOWNROLL,
		RIGHTATTACK,
		LEFTATTACK,
		UPATTACK,
		DOWNATTACK
	};

	ZeroAnimation* playerSrun;
	ZeroAnimation* playerUrun;
	ZeroAnimation* playerDrun;
	ZeroAnimation* playerSidle; 
	ZeroAnimation* playerUidle; 
	ZeroAnimation* playerDidle; 
	ZeroAnimation* playerSroll;
	ZeroAnimation* playerUroll;
	ZeroAnimation* playerDroll;
	ZeroAnimation* playerSattack;
	ZeroAnimation* playerUattack;
	ZeroAnimation* playerDattack;

	
	ZeroSprite* collider;


	int speed;
	int defaultHealth;

	float stamina;
	float attackPower;
	float health;

	bool isAlive;
	bool canInput;

	void Update(float eTime) override;
	void Render() override;
	void SetAbility(int type);

};

