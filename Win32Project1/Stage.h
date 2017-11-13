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
	ZeroFont* staminaText;

	virtual void CheckOut();
	virtual void CheckOut(float eTime);
	virtual void PopStage();
};

