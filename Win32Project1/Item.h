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
		�츣�޽� �Ź� [SPEED +2]
���� [HEALTH +2]
¯�� [DAMAGE +2]
�۷κ� [DAMAGE +1 / SPEED +1]
���� [SPEED +1 / HEALTH +1]
��� [HEALTH +1/DAMAGE +1]
		*/
};

