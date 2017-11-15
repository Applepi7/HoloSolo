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

	void PopStage() override;

public:
	FourthStage();

	void Update(float eTime) override;
	void Render() override;

	void CheckOut(float eTime) override;
};

