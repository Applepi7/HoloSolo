#include "stdafx.h"
#include "Item.h"


Item::Item()
{
	itemImage = new ZeroSprite("Resource/Item/item_spare.png");
	PushScene(itemImage);

	SetPos(640 - itemImage->Width() * 0.5f, 355 - itemImage->Height() * 0.5f);
}


Item::~Item()
{
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
