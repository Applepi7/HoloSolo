#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroFont.h"

#include "PlayerCharacter.h"


class Item :
	public ZeroIScene
{
private:
	int type;

public:

	enum ITEM 
	{
		SHOES,
		DUMBBELL,	
		ROCK,
		GLOVE,
		CLOAK,
		HELMET
	};

	Item();

	void Update(float eTime) override;
	void Render() override;

	ZeroSprite* itemImage;
	ZeroFont* effectText;

	bool IsCollision(PlayerCharacter* player);

	void GiveAbility(PlayerCharacter* player);


		/*
		�츣�޽� �Ź� [SPEED +2]
���� [HEALTH +2]
¯�� [DAMAGE +2]
�۷κ� [DAMAGE +1 / SPEED +1]
���� [SPEED +1 / HEALTH +1]
��� [HEALTH +1/DAMAGE +1]
		*/
};

