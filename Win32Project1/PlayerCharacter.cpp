#include "stdafx.h"
#include "PlayerCharacter.h"

#include "ZeroInputManager.h"

PlayerCharacter::PlayerCharacter() : isMove(false), speed(200), playerCondition(5), prevKey(NULL)
{

	playerSrun = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 4; i++) {
		playerSrun->PushSprite("Resource/Run/run_side_%d.png", i);
	}

	playerUrun = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		playerUrun->PushSprite("Resource/Run/run_back_%d.png", i);
	}

	playerDrun = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		playerDrun->PushSprite("Resource/Run/run_front_%d.png", i);
	}

	playerSidle = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		playerSidle->PushSprite("Resource/Idle/idle_side_%d.png", i);
	}

	playerUidle = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		playerUidle->PushSprite("Resource/Idle/idle_back_%d.png", i);
	}

	playerDidle = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		playerDidle->PushSprite("Resource/Idle/idle_front_%d.png", i);
	}

	playerSrun->SetScalingCenter(playerSrun->Width() * 0.5f);
	playerSidle->SetScalingCenter(playerSidle->Width() * 0.5f);

	PushScene(playerSrun);
	PushScene(playerUrun);
	PushScene(playerDrun);

	PushScene(playerSidle);
	PushScene(playerUidle);
	PushScene(playerDidle);

	SetPos(600, 350);
}

void PlayerCharacter::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	playerSrun->Update(eTime);
	playerUrun->Update(eTime);
	playerDrun->Update(eTime);
	playerSidle->Update(eTime);
	playerUidle->Update(eTime);
	playerDidle->Update(eTime);

	Move(eTime);
	Idle();
}

void PlayerCharacter::Render()
{
	ZeroIScene::Render();

	switch (playerCondition)
	{
	case RIGHTRUN:
		playerSrun->Render();
		playerSrun->SetScale(-1, 1);
		break;
	case LEFTRUN:
		playerSrun->Render();
		playerSrun->SetScale(1, 1);
		break;
	case UPRUN:
		playerUrun->Render();
		break;
	case DOWNRUN:
		playerDrun->Render();
		break;
	case RIGHTIDLE:
		playerSidle->Render();
		playerSidle->SetScale(-1, 1);
		break;
	case LEFTIDLE:
		playerSidle->Render();
		playerSidle->SetScale(1, 1);
		break;
	case UPIDLE:
		playerUidle->Render();
		break;
	case DOWNIDLE:
		playerDidle->Render();
		break;
	}
}

void PlayerCharacter::Move(float eTime)
{
	if (ZeroInputMgr->GetKey(VK_RIGHT) == INPUTMGR_KEYON) {
		if (Pos().x <= 1280 - playerSrun->Width()) {
			AddPosX(speed * eTime);
			playerCondition = RIGHTRUN;

			prevKey = VK_RIGHT;
			isMove = true;
		}
	}
	else isMove = false;
	
	if (ZeroInputMgr->GetKey(VK_LEFT) == INPUTMGR_KEYON) {
		if (Pos().x >= 0) {
			AddPosX(-speed * eTime);
			playerCondition = LEFTRUN;

			prevKey = VK_LEFT;
			isMove = true;
		}
	}
	
	if (ZeroInputMgr->GetKey(VK_UP) == INPUTMGR_KEYON) {
		if (Pos().y >= 0) {
			AddPosY(-speed * eTime);
			playerCondition = UPRUN;

			prevKey = VK_UP;
			isMove = true;
		}
	}
	
	if (ZeroInputMgr->GetKey(VK_DOWN) == INPUTMGR_KEYON) {
		if (Pos().y <= 720 - playerSrun->Height()) {
			AddPosY(speed * eTime);
			playerCondition = DOWNRUN;

			prevKey = VK_DOWN;
			isMove = true;
		}
	}
}

void PlayerCharacter::Idle()
{
	if (!isMove) {
		switch (prevKey)
		{
		case VK_RIGHT:
			playerCondition = RIGHTIDLE;
			break;
		case VK_LEFT:
			playerCondition = LEFTIDLE;
			break;
		case VK_UP:
			playerCondition = UPIDLE;
			break;
		case VK_DOWN:
			playerCondition = DOWNIDLE;
			break;
		}
	}
}