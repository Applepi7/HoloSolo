#pragma once

#include "ZeroInputManager.h"
#include "ZeroSprite.h"

#include "ZeroIScene.h"
class MenuScene :
	public ZeroIScene
{
private:
	int page;

	bool isStart;

	void ShowHowTo();

public:
	MenuScene();

	ZeroSprite* startBtn;
	ZeroSprite* howtoBtn;
	ZeroSprite* prolBtn;

	ZeroSprite* howToPage1;
	ZeroSprite* howToPage2;
	ZeroSprite* nextPageBtn;
	ZeroSprite* prevPageBtn;
	ZeroSprite* startGameBtn;

	ZeroSprite* background;

	void Update(float eTime) override;
	void Render() override;
};

