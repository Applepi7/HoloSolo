#pragma once
#include "ZeroIScene.h"

#include "ZeroAnimation.h"


class PlayerCharacter :
	public ZeroIScene
{
private:

	enum CONDITION{
		RIGHTRUN,
		LEFTRUN,
		UPRUN,
		DOWNRUN,
		RIGHTIDLE,
		LEFTIDLE,
		UPIDLE,
		DOWNIDLE
	};

	bool isMove;

	int playerCondition;
	int prevKey;

	void Move(float eTime);
	void Idle();

public:
	PlayerCharacter();

	ZeroAnimation* playerSrun;
	ZeroAnimation* playerUrun;
	ZeroAnimation* playerDrun;
	ZeroAnimation* playerSidle; 
	ZeroAnimation* playerUidle; 
	ZeroAnimation* playerDidle; 

	float speed;

	void Update(float eTime) override;
	void Render() override;
};

