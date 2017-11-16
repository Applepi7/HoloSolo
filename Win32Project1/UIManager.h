#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"

#include "PlayerCharacter.h"
#include "Enemy.h"

#include "Slime.h"
#include "Wisp.h"
#include "Totem.h"
#include "Golem.h"
#include "Dragon.h"

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

	ZeroSprite* enemyHealthBar;
	ZeroSprite* enemyHealthFill;

	void Update(float eTime) override;
	void Render() override;

	void PlayerUI(PlayerCharacter* player);
	void EnemyUI(Enemy* enemy);

};

