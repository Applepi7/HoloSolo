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
	
	bool isStartPress;
	bool isHowToPress;
	bool isProlPress;

	void ShowHowTo();

public:
	MenuScene();

	ZeroSprite* startBtn;
	ZeroSprite* startBtnPress;
	ZeroSprite* howtoBtn;
	ZeroSprite* howtoBtnPress;
	ZeroSprite* prolBtn;
	ZeroSprite* prolBtnPress;

	ZeroSprite* howToPage1;
	ZeroSprite* howToPage2;
	ZeroSprite* nextPageBtn;
	ZeroSprite* prevPageBtn;
	ZeroSprite* startGameBtn;

	ZeroSprite* background;

	void Update(float eTime) override;
	void Render() override;
};

