#pragma once

#include "ZeroInputManager.h"
#include "ZeroSprite.h"
#include "ZeroSceneManager.h"

#include "ZeroIScene.h"
class CartoonScene
	: public ZeroIScene
{
private:
	int index;

	ZeroSprite* page1;
	ZeroSprite* page2;
	ZeroSprite* page3;
	ZeroSprite* page4;

public:
	CartoonScene();
	~CartoonScene();

	void Update(float eTime) override;
	void Render() override;
};

