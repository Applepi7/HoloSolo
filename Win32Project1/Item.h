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
		Çì¸£¸Þ½º ½Å¹ß [SPEED +2]
´ýº§ [HEALTH +2]
Â¯µ¹ [DAMAGE +2]
±Û·Îºê [DAMAGE +1 / SPEED +1]
¸ÁÅä [SPEED +1 / HEALTH +1]
Çï¸ä [HEALTH +1/DAMAGE +1]
		*/
};

