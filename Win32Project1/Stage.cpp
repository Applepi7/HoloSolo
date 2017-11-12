#include "stdafx.h"
#include "Stage.h"

#include "ZeroSoundManager.h"


Stage::Stage()
{
	item = new Item();
	PushScene(item);
}

void Stage::CheckOut()
{
}

void Stage::CheckOut(float eTime)
{
}

void Stage::PopStage()
{
}
