#pragma once
#include "Stage.h"
#include "ZeroSprite.h"

#include "PlayerCharacter.h"
#include "Slime.h"

class FirstStage :
	public Stage
{
private:
	list<Slime*> slimeList;
	PlayerCharacter* player;

	ZeroSprite* background;

	Item* item;

	void CheckOut() override;
	void SpawnItem();

public:
	FirstStage();

	int slimeNum;

	void Update(float eTime) override;
	void Render() override;
};

