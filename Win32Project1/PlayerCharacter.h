#pragma once
#include "ZeroIScene.h"

#include "ZeroAnimation.h"


class PlayerCharacter :
	public ZeroIScene
{
private:

	void Input(float eTime);

public:
	PlayerCharacter();
	~PlayerCharacter();

	ZeroAnimation* player;

	float speed;

	void Update(float eTime) override;
	void Render() override;
};

