#pragma once
#include "ZeroIScene.h"

#include "ZeroAnimation.h"


class PlayerCharacter :
	public ZeroIScene
{
private:

	pair<float, float> rollTimer;

	bool isMove;
	bool isRoll;
	bool isKeydown;

	int playerCondition;
	int prevKey;

	void Move(float eTime);
	void Idle();

public:
	PlayerCharacter();

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

	float speed;

	void Update(float eTime) override;
	void Render() override;
};

