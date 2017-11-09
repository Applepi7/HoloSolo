#pragma once
#include "Stage.h"
#include "ZeroSprite.h"

#include "PlayerCharacter.h"
#include "Slime.h"

#include <list>
class FirstStage :
	public Stage
{
private:
	list<Slime*> slimeList;
	PlayerCharacter* player;

	ZeroSprite* background;

	void CheckOut() override;

public:
	FirstStage();

	void Update(float eTime) override;
	void Render() override;
};

