#include "stdafx.h"
#include "Enemy.h"

#include <math.h>

Enemy::Enemy() : speed(150)
{
}


Enemy::~Enemy()
{
}

void Enemy::FollowPlayer()
{
}

void Enemy::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	
}

void Enemy::Render()
{
	ZeroIScene::Render();
}

void Enemy::IsCollision(PlayerCharacter * player, Enemy * enemy)
{
}

void Enemy::Follow(PlayerCharacter * target, Enemy * enemy, float eTime, bool isMove)
{
	float rot = atan2(target->Pos().y - enemy->Pos().y, target->Pos().x - enemy->Pos().x);
	if (isMove) {
		enemy->SetPos(enemy->Pos() += ZeroVec(cos(rot), sin(rot)) * enemy->speed * eTime);
	}
}
