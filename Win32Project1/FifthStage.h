#pragma once
#include "Stage.h"
#include "ZeroSprite.h"

#include "PlayerCharacter.h"
#include "Dragon.h"


class FifthStage :
	public Stage
{
private:
	PlayerCharacter* player;
	Dragon* dragon;

	ZeroSprite* background;

	void CheckOut(float eTime) override;

public:
	FifthStage();

	void Update(float eTime) override;
	void Render() override;


};

