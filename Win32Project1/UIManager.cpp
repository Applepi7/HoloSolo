#include "stdafx.h"
#include "UIManager.h"


UIManager::UIManager()
{
	healthBar = new ZeroSprite("Resource/UI/InGame/Player/bg_hp_bar.png");
	healthFill = new ZeroSprite("Resource/UI/InGame/Player/ic_hp_bar.png");
	staminaBar = new ZeroSprite("Resource/UI/InGame/Player/bg_sp_bar.png");
	staminaFill = new ZeroSprite("Resource/UI/InGame/Player/ic_sp_bar.png");

	enemyHealthBar = new ZeroSprite("Resource/UI/InGame/Enemy/bg_monster_hp_bar.png");
	enemyHealthFill = new ZeroSprite("Resource/UI/InGame/Enemy/ic_monster_hp_bar.png");

	PushScene(healthBar);
	PushScene(healthFill);
	PushScene(staminaBar);
	PushScene(staminaFill);

	PushScene(enemyHealthBar);
	PushScene(enemyHealthFill);

	healthBar->SetPos(0, 0);
	healthFill->SetPos(53, 15);
	staminaBar->SetPos(0, 50);
	staminaFill->SetPos(53, 65);

	enemyHealthBar->SetPos(640 - enemyHealthBar->Width() * 0.5f, 0);
	enemyHealthFill->SetPos(640 - enemyHealthFill->Width() * 0.35f, 23);
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

void UIManager::PlayerUI(PlayerCharacter * player)
{
	if (player->health >= 0) {
		switch (player->defaultHealth)
		{
		case 100:
			healthFill->SetScale(player->health * 0.01, 1);
			break;
		case 125:
			healthFill->SetScale(player->health * 0.008, 1);
			break;
		case 150:
			healthFill->SetScale(player->health * 0.0067, 1);
			break;
		}
	}
	else
		healthFill->SetScale(0, 1);

	if (player->stamina >= 0)
		staminaFill->SetScale(player->stamina * 0.01, 1);
	else
		staminaFill->SetScale(0, 1);
}

void UIManager::EnemyUI(Enemy* enemy)
{
	float enemyHealth[5] = { 0.011, 0.01, 0.0067, 0.0025, 0.001 };
	enemyHealthFill->SetScale(enemy->health * enemyHealth[enemy->enemyType], 1);
}
