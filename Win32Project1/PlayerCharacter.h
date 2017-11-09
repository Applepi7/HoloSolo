#pragma once
#include "ZeroIScene.h"

#include "ZeroAnimation.h"

class PlayerCharacter :
	public ZeroIScene
{
private:

	pair<float, float> rollTimer;
	pair<float, float> attackTimer;

	bool isMove;
	bool isRoll;
	bool isKeydown;

	int playerCondition;
	int prevKey;

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

	float speed;
	float health;

	void Update(float eTime) override;
	void Render() override;
};

