#include "stdafx.h"
#include "Enemy.h"


#include <math.h>

Enemy::Enemy() : followDistanceX(300), followDistanceY(300), damagedTimer(0, 1)
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

void Enemy::Follow(PlayerCharacter * target, Enemy * enemy, int speed, float eTime, bool isMove)
{
	float rot = atan2(target->Pos().y - enemy->Pos().y, target->Pos().x - enemy->Pos().x);
	// 아크 탄잰트를 사용하여 타겟의 위치로 각도를 잡는다
	if(abs(target->Pos().x - enemy->Pos().x) <= followDistanceX && abs(target->Pos().y - enemy->Pos().y) <= followDistanceY)
		if(isMove)
			enemy->AddPos(cos(rot), sin(rot) * speed * eTime);

}

void Enemy::Damage(PlayerCharacter * player)
{
}

void Enemy::Damage(PlayerCharacter * player, float eTime)
{
}

bool Enemy::IsCollision(PlayerCharacter* player)
{
	return false;
}
