#pragma once
#include "Stage.h"
#include "ZeroSprite.h"

#include "PlayerCharacter.h"
#include "Totem.h"


class ThirdStage :
	public Stage
{
private:
	PlayerCharacter* player;
	list<Totem*> totemList;

	ZeroSprite* background;

	void CheckOut() override;
public:
	ThirdStage();

	void Update(float eTime) override;
	void Render() override;
};

