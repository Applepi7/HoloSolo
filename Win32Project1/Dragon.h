#pragma once
#include "Enemy.h"

#include "ZeroAnimation.h"

class Dragon :
	public Enemy
{
private:
	enum DragonCondition
	{
		IDLE,
		WIND,
		WING,
		THUNDER,
		FIRE
	};

	pair<float, float> attackTimer;
	pair<float, float> windTimer;
	pair<float, float> wingTimer;
	pair<float, float> thunderTimer;
	pair<float, float> fireTimer;
	pair<float, float> damageTimer;

	pair<float, float> moveTimer;
	pair<float, float> downTimer;

	int index;

	bool isDown;
	bool isUp;
	bool canDown;

public:
	Dragon();

	DragonCondition dragonCondition;

	bool isAlive;

	void Update(float eTime) override;
	void Render() override;
	void Attack(PlayerCharacter* player, float eTime);

	void Damage(PlayerCharacter* player, float eTime) override;
	bool IsCollision(PlayerCharacter* player) override;
	bool IsCollision(PlayerCharacter* player, ZeroAnimation* anim);


	ZeroAnimation* dragonIdle;
	ZeroAnimation* dragonWing;
	ZeroAnimation* dragonThunder;
	ZeroAnimation* dragonWind;
	ZeroAnimation* dragonFire;

	ZeroAnimation* dBreath;
	ZeroAnimation* dThunder;
	ZeroAnimation* dWaveLength;
	ZeroAnimation* dFire;
};

