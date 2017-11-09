#pragma once
#include "Stage.h"
#include "ZeroSprite.h"

#include "PlayerCharacter.h"
#include "Wisp.h"

class SecondStage :
	public Stage
{
private:
	PlayerCharacter* player;
	list<Wisp*> wispList;

	ZeroSprite* background;

	void CheckOut() override;

public:
	SecondStage();

	void Update(float eTime) override;
	void Render() override;

	
};

