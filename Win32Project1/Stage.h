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

	virtual void CheckOut();
	virtual void CheckOut(float eTime);
};

