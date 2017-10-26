#pragma once
#include "ZeroIScene.h"

#include "PlayerCharacter.h"

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

	bool isAlive;
	int speed;

	void Update(float eTime) override;
	void Render() override;

	virtual void IsCollision(PlayerCharacter* player, Enemy* enemy);

	void Follow(PlayerCharacter* target, Enemy* enemy, float eTime, bool isMove);
};

