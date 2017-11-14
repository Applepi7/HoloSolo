#include "stdafx.h"
#include "Stage.h"

#include "ZeroSoundManager.h"


Stage::Stage()
{
	item = new Item();

	healthText = new ZeroFont(20, "", "LuckiestGuy");
	damageText = new ZeroFont(20, "", "LuckiestGuy");
	speedText = new ZeroFont(20, "", "LuckiestGuy");

	PushScene(item);
	PushScene(damageText);
	PushScene(healthText);
	PushScene(speedText);

	damageText->SetPos(100, 600);
	healthText->SetPos(300, 600);
	speedText->SetPos(500, 600);

}

void Stage::CheckOut()
{
}

void Stage::CheckOut(float eTime)
{
}

void Stage::PopStage()
{
}

bool Stage::IsCollision(PlayerCharacter * player, Item * item)
{
	if (
		(player->Pos().x - item->Pos().x <= item->itemImage->Width()) &&
		(item->Pos().x - player->Pos().x <= player->playerSidle->Width()) &&
		(item->Pos().y - player->Pos().y <= player->playerSidle->Height()) &&
		(player->Pos().y - item->Pos().y <= item->itemImage->Height())
		)
		return true;
	else
		return false;
}
