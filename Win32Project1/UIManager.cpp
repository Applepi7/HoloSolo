#include "stdafx.h"
#include "UIManager.h"


UIManager::UIManager()
{
	healthBar = new ZeroSprite("Resource/UI/InGame/Player/bg_hp_bar.png");
	healthFill = new ZeroSprite("Resource/UI/InGame/Player/ic_hp_bar.png");
	staminaBar = new ZeroSprite("Resource/UI/InGame/Player/bg_sp_bar.png");
	staminaFill = new ZeroSprite("Resource/UI/InGame/Player/ic_sp_bar.png");

	PushScene(healthBar);
	PushScene(healthFill);
	PushScene(staminaBar);
	PushScene(staminaFill);

	healthBar->SetPos(0, 0);
	healthFill->SetPos(53, 15);
	staminaBar->SetPos(0, 50);
	staminaFill->SetPos(53, 65);
}


UIManager::~UIManager()
{
}

void UIManager::Update(float eTime)
{
	ZeroIScene::Update(eTime);

}

void UIManager::Render()
{
	ZeroIScene::Render();

	
}
