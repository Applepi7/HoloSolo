#pragma once

#include "PlayerCharacter.h"

#include "ZeroIScene.h"
class ExampleScene :
	public ZeroIScene
{
public:
	ExampleScene();
	~ExampleScene();

	PlayerCharacter* player;

	void Update(float eTime) override;
	void Render() override;
};

