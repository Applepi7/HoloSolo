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

	UIManager* ui;

	ZeroSprite* background;

	int wispNum;

	pair<float, float> damageTimer;

	void CheckOut(float eTime) override;

public:
	SecondStage();

	void Update(float eTime) override;
	void Render() override;

	void PopStage() override;
};

