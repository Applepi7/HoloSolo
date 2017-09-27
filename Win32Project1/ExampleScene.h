#pragma once

#include "PlayerCharacter.h"
#include "Slime.h"

#include "ZeroIScene.h"

#include "ZeroSprite.h"
class ExampleScene :
	public ZeroIScene
{
public:
	ExampleScene();
	~ExampleScene();

	PlayerCharacter* player;
	Slime* slime;

	ZeroSprite* background;

	void Update(float eTime) override;
	void Render() override;
};

