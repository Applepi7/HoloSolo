#pragma once

#include "ZeroAnimation.h"
#include "ZeroSprite.h"

#include "Enemy.h"

class Slime :
	public Enemy
{
public:
	Slime();
	~Slime();

	int speed = 150;

	ZeroAnimation* slime;

	void Update(float eTime) override;
	void Render() override;
};

