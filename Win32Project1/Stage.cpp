#include "stdafx.h"
#include "Stage.h"

#include "ZeroSoundManager.h"
#include "ZeroInputManager.h"

#include "MenuScene.h"


Stage::Stage()
{
	item = new Item();
	//ui = new UIManager();

	healthText = new ZeroFont(30, "", "Luckiest Guy");
	damageText = new ZeroFont(30, "", "Luckiest Guy");
	speedText = new ZeroFont(30, "", "Luckiest Guy");

	failSprite = new ZeroSprite("Resource/UI/Result/fail.png");
	failBackground = new ZeroSprite("Resource/UI/Result/failBackground.png");

	PushScene(item);
	//PushScene(ui);

	PushScene(damageText);
	PushScene(healthText);
	PushScene(speedText);

	PushScene(failSprite);
	PushScene(failBackground);

	healthText->SetPos(100, 670);
	damageText->SetPos(300, 670);
	speedText->SetPos(500, 670);

	damageText->SetColorR(32);
	damageText->SetColorG(164);
	damageText->SetColorB(0);

	healthText->SetColorR(199);
	healthText->SetColorG(0);
	healthText->SetColorB(0);

	speedText->SetColorR(0);
	speedText->SetColorG(0);
	speedText->SetColorB(168);

}

void Stage::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void Stage::Render()
{
	ZeroIScene::Render();
}

void Stage::ShowResult(PlayerCharacter* player, float eTime)
{
	static float a = 0;
	
	if (!player->isAlive) {
		a += eTime * 120;
		player->canInput = false;
		if (a <= 255)
			failBackground->SetColorA((int)a);
		else
		{
			static float alpha = 0;
			alpha += eTime * 120;
			if (alpha <= 255)
				failSprite->SetColorA((int)alpha);
			else
				if (ZeroInputMgr->GetKey(VK_ESCAPE) == INPUTMGR_KEYDOWN)
					ZeroSceneMgr->ChangeScene(new MenuScene());
		}
	}
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
