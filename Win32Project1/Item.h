#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroFont.h"

#include "PlayerCharacter.h"

class Item :
	public ZeroIScene
{

public:
	int type;

	enum ITEM 
	{
		SHOES,
		DUMBBELL,	
		ROCK,
		GLOVE,
		CLOAK,
		HELMET,
		NONE
	};

	Item();

	float pHealth;
	float pSpeed;
	float pDamage;

	void Update(float eTime) override;
	void Render() override;

	ZeroSprite* itemImage;
	ZeroFont* effectText;

		

};

