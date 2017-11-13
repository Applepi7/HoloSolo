#pragma once

#include "ZeroInputManager.h"
#include "ZeroSprite.h"

#include "ZeroIScene.h"
class MenuScene :
	public ZeroIScene
{
private:
	
	void ShowHowTo();

public:
	MenuScene();

	ZeroSprite* startBtn;
	ZeroSprite* howtoBtn;
	ZeroSprite* prolBtn;

	ZeroSprite* howToPage1;
	ZeroSprite* howToPage2;

	ZeroSprite* background;

	void Update(float eTime) override;
	void Render() override;
};

