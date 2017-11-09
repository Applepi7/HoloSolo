#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"

#include "PlayerCharacter.h"
#include "Slime.h"

#include <list>
class FirstStage :
	public ZeroIScene
{
private:
	list<Slime*> slimeList;
	PlayerCharacter* player;

	ZeroSprite* background;

public:
	FirstStage();

	void Update(float eTime) override;
	void Render() override;

	void CheckOut();
};

