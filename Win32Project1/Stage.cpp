#include "stdafx.h"
#include "Stage.h"

#include "ZeroSoundManager.h"


Stage::Stage()
{
	item = new Item();

	healthText = new ZeroFont(20, "", "LuckiestGuy");
	damageText = new ZeroFont(20, "", "LuckiestGuy");
	staminaText = new ZeroFont(20, "", "LuckiestGuy");

	PushScene(item);
	PushScene(damageText);
	PushScene(healthText);
	PushScene(staminaText);

	damageText->SetPos(100, 600);
	healthText->SetPos(300, 600);
	staminaText->SetPos(500, 600);

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
