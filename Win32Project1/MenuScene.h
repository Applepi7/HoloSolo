#pragma once

#include "ZeroInputManager.h"
#include "ZeroSprite.h"

#include "ZeroIScene.h"
class MenuScene :
	public ZeroIScene
{
public:
	MenuScene();
	~MenuScene();

	ZeroSprite* btn;

	void Update(float eTime) override;
	void Render() override;
};

