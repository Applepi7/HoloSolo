#pragma once
#include "ZeroIScene.h"

#include "ZeroSceneManager.h"

#include "Item.h"

#include <list>
class Stage :
	public ZeroIScene
{
public:
	Stage();

	Item* item;

	ZeroFont* damageText;
	ZeroFont* healthText;
	ZeroFont* speedText;

	virtual void CheckOut();
	virtual void CheckOut(float eTime);
	virtual void PopStage();

	bool IsCollision(PlayerCharacter* player, Item* item);

};

