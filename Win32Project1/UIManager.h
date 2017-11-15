#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"


class UIManager :
	public ZeroIScene
{
public:
	UIManager();
	~UIManager();

	ZeroSprite* healthBar;
	ZeroSprite* healthFill;
	ZeroSprite* staminaBar;
	ZeroSprite* staminaFill;

	void Update(float eTime) override;
	void Render() override;

};

