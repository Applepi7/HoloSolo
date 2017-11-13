#include "stdafx.h"
#include "Item.h"

#include "Random.h"

Item::Item() : type(RandomInt(0, 5))
{
	switch (type)
	{
	case SHOES:
		itemImage = new ZeroSprite("Resource/Item/shoes.png");
		break;
	case DUMBBELL:
		itemImage = new ZeroSprite("Resource/Item/dumbbell.png");
		break;
	case ROCK:
		itemImage = new ZeroSprite("Resource/Item/rock.png");
		break;
	case GLOVE:
		itemImage = new ZeroSprite("Resource/Item/glove.png");
		break;
	case CLOAK:
		itemImage = new ZeroSprite("Resource/Item/cloak.png");
		break;
	case HELMET:
		itemImage = new ZeroSprite("Resource/Item/helmet.png");
		break;
	}
	PushScene(itemImage);

	SetPos(640 - itemImage->Width() * 0.5f, 355 - itemImage->Height() * 0.5f);
}


void Item::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	itemImage->Update(eTime);
}

void Item::Render()
{
	ZeroIScene::Render();

	itemImage->Render();
}

bool Item::IsCollision(PlayerCharacter * player)
{
	if (
		(player->Pos().x - Pos().x <= itemImage->Width()) &&
		(Pos().x - player->Pos().x <= player->playerSidle->Width()) &&
		(Pos().y - player->Pos().y <= player->playerSidle->Height()) &&
		(player->Pos().y - Pos().y <= itemImage->Height())
	   )
		return true;
	else
		return false;
}

void Item::GiveAbility(PlayerCharacter * player)
{
	switch (type)
	{
	case SHOES:
		player->speed = 500;
		player->health = 100;
		player->attackPower = 50;
		break;
	case DUMBBELL:
		player->speed = 500;
		player->health = 150;
		player->attackPower = 50;
		break;
	case ROCK:
		player->speed = 500;
		player->health = 100;
		player->attackPower = 100;
		break;
	case GLOVE:
		player->speed = 500;
		player->health = 100;
		player->attackPower = 125;
		break;
	case CLOAK:
		player->speed = 500;
		player->health = 125;
		player->attackPower = 75;
		break;
	case HELMET:
		player->speed = 500;
		player->health = 125;
		player->attackPower = 75;
		break;
	}
}
