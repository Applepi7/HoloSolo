#pragma once
#include "Stage.h"
#include "ZeroSprite.h"

#include "PlayerCharacter.h"
#include "Golem.h"

class FourthStage :
	public Stage
{
private:
	PlayerCharacter* player;
	Golem* golem;

	ZeroSprite* background;

public:
	FourthStage();

	void Update(float eTime) override;
	void Render() override;
};

