#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"

#include "PlayerCharacter.h"


class Item :
	public ZeroIScene
{
public:

	enum ITEM 
	{
		SHOES,
		DUMBEL,
		ROCK,
		GLOBE,
		CLOCK,
		HELMET
	};

	Item();
	~Item();

	void Update(float eTime) override;
	void Render() override;

	ZeroSprite* itemImage;

	bool IsCollision(PlayerCharacter* player);


		/*
		Çì¸£¸Þ½º ½Å¹ß [SPEED +2]
´ýº§ [HEALTH +2]
Â¯µ¹ [DAMAGE +2]
±Û·Îºê [DAMAGE +1 / SPEED +1]
¸ÁÅä [SPEED +1 / HEALTH +1]
Çï¸ä [HEALTH +1/DAMAGE +1]
		*/
};

