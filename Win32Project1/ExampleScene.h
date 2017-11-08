#pragma once

#include "PlayerCharacter.h"
#include "Slime.h"
#include "Wisp.h"
#include "Totem.h"

#include "Golem.h"
#include "Dragon.h"

#include "ZeroIScene.h"

#include "ZeroSprite.h"
class ExampleScene :
	public ZeroIScene
{
public:
	ExampleScene();

	PlayerCharacter* player;

	Slime* slime;
	Wisp* wisp;
	Totem* totem;
	Golem* golem;
	Dragon* dragon;

	ZeroSprite* background;

	void Update(float eTime) override;
	void Render() override;
};

