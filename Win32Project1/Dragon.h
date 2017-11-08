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

	int index;

public:
	Dragon();

	DragonCondition dragonCondition;

	void Update(float eTime) override;
	void Render() override;
	void Attack(float eTime);

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

