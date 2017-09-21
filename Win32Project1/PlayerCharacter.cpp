#include "stdafx.h"
#include "PlayerCharacter.h"

#include "ZeroInputManager.h"

PlayerCharacter::PlayerCharacter() : isMove(false), isRoll(false), speed(100), playerCondition(LEFTIDLE), prevKey(NULL), rollTimer(0, .7f)
{

	playerSrun = new ZeroAnimation(1.5f);
	for (int i = 1; i <= 4; i++) {
		playerSrun->PushSprite("Resource/Run/run_side_%d.png", i);
	}

	playerUrun = new ZeroAnimation(1.5f);
	for (int i = 1; i <= 2; i++) {
		playerUrun->PushSprite("Resource/Run/run_back_%d.png", i);
	}

	playerDrun = new ZeroAnimation(1.5f);
	for (int i = 1; i <= 2; i++) {
		playerDrun->PushSprite("Resource/Run/run_front_%d.png", i);
	}

	/*-------------------------------------------------------------------------*/

	playerSidle = new ZeroAnimation(1.5f);
	for (int i = 1; i <= 2; i++) {
		playerSidle->PushSprite("Resource/Idle/idle_side_%d.png", i);
	}

	playerUidle = new ZeroAnimation(1.5f);
	for (int i = 1; i <= 2; i++) {
		playerUidle->PushSprite("Resource/Idle/idle_back_%d.png", i);
	}

	playerDidle = new ZeroAnimation(1.5f);
	for (int i = 1; i <= 2; i++) {
		playerDidle->PushSprite("Resource/Idle/idle_front_%d.png", i);
	}

	/*-------------------------------------------------------------------------*/

	playerSroll = new ZeroAnimation(2.0f);
	for (int i = 1; i <= 4; i++) {
		playerSroll->PushSprite("Resource/Roll/roll_side_%d.png", i);
	}

	playerUroll = new ZeroAnimation(2.0f);
	for (int i = 1; i <= 4; i++) {
		playerUroll->PushSprite("Resource/Roll/roll_back_%d.png", i);
	}
	
	playerDroll = new ZeroAnimation(2.0f);
	for (int i = 1; i <= 4; i++) {
		playerDroll->PushSprite("Resource/Roll/roll_front_%d.png", i);
	}
	
	playerSrun->SetScalingCenter(playerSrun->Width() * 0.5f);
	playerSidle->SetScalingCenter(playerSidle->Width() * 0.5f);
	playerSroll->SetScalingCenter(playerSroll->Width() * 0.5f);

	PushScene(playerSrun);
	PushScene(playerUrun);
	PushScene(playerDrun);

	PushScene(playerSidle);
	PushScene(playerUidle);
	PushScene(playerDidle);

	PushScene(playerSroll);
	PushScene(playerUroll);
	PushScene(playerDroll);

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
	playerSroll->Update(eTime);
	playerUroll->Update(eTime);
	playerDroll->Update(eTime);

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
	case RIGHTROLL:
		playerSroll->Render();
		playerSroll->SetScale(-1, 1);
		break;
	case LEFTROLL:
		playerSroll->Render();
		playerSroll->SetScale(1, 1);
		break;
	case UPROLL:
		playerUroll->Render();
		break; 
	case DOWNROLL:
		playerDroll->Render();
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

	if (ZeroInputMgr->GetKey('X') == INPUTMGR_KEYDOWN) {
		isRoll = true;
		
	}

	if (isRoll) {
		rollTimer.first += eTime;
		
		if (rollTimer.first >= rollTimer.second) {
			isRoll = false;
			rollTimer.first = 0;
		}

		speed = 200;
		switch (prevKey)
		{
		case VK_RIGHT:
			playerCondition = RIGHTROLL;
			break;
		case VK_LEFT:
			playerCondition = LEFTROLL;
			break;
		case VK_UP:
			playerCondition = UPROLL;
			break;
		case VK_DOWN:
			playerCondition = DOWNROLL;
			break;
		}
	}
	else speed = 100;
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

void PlayerCharacter::Roll()
{
}
