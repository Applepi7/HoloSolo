#pragma once
#include "ZeroIScene.h"

#include "PlayerCharacter.h"

#include "ZeroSoundManager.h"


class Enemy :
	public ZeroIScene
{
public:
	Enemy();
	~Enemy();

protected:
	void FollowPlayer();

	enum CONDITION {
		MOVE,
		ATTACK,
		IDLE
	};

public:

	int speed;
	
	float health;

	void Update(float eTime) override;
	void Render() override;

	void Follow(PlayerCharacter* target, Enemy* enemy, float eTime, bool isMove);

	virtual void Damage(PlayerCharacter* player);
	virtual void Damage(PlayerCharacter* player, float eTime);
	virtual bool IsCollision(PlayerCharacter* player);
};

