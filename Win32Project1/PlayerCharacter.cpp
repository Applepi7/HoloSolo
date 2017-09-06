#include "stdafx.h"
#include "PlayerCharacter.h"

#include "ZeroInputManager.h"

PlayerCharacter::PlayerCharacter() : speed(200)
{
	player = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		player->PushSprite("Resource/Idle/idle_front_%d.png", i);
	}
	PushScene(player);
	SetPos(600, 350);
}


PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	player->Update(eTime);

	Input(eTime);
}

void PlayerCharacter::Render()
{
	ZeroIScene::Render();
	player->Render();
}

void PlayerCharacter::Input(float eTime)
{
	if (ZeroInputMgr->GetKey(VK_RIGHT) == INPUTMGR_KEYON) {
		if (Pos().x <= 1280 - player->Width()) {
			AddPosX(speed * eTime);
			for (int i = 1; i <= 4; i++) {
				player->PushSprite("Resource/Run/run_side_%d.png", i);
				player->SetScale(-1, 1);
			}
		}
	}
	if (ZeroInputMgr->GetKey(VK_LEFT) == INPUTMGR_KEYON) {
		if (Pos().x >= 0) {
			AddPosX(-speed * eTime);
			for (int i = 1; i <= 4; i++) {
				player->PushSprite("Resource/Run/run_side_%d.png", i);
				player->SetScale(1, 1);
			}
		}
	}
	if (ZeroInputMgr->GetKey(VK_UP) == INPUTMGR_KEYON) {
		if (Pos().y >= 0) {
			AddPosY(-speed * eTime);
		}
	}
	if (ZeroInputMgr->GetKey(VK_DOWN) == INPUTMGR_KEYON) {
		if (Pos().y <= 720 - player->Height()) {
			AddPosY(speed * eTime);
		}
	}
}