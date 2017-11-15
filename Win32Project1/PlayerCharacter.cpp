#include "stdafx.h"
#include "PlayerCharacter.h"

#include "ZeroInputManager.h"
#include "ZeroSoundManager.h"
#include "GameManager.h"

#include "Random.h"

PlayerCharacter::PlayerCharacter() : isAlive(true), isMove(false), isRoll(false), isAttack(false),health(100), speed(100), attackPower(50), stamina(100), playerCondition(LEFTIDLE), prevKey(VK_LEFT), rollTimer(0, .7f), attackTimer(0, .7f)
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

	/*-------------------------------------------------------------------------*/

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

	/*-------------------------------------------------------------------------*/

	playerSroll = new ZeroAnimation(6.0f);
	for (int i = 1; i <= 4; i++) {
		playerSroll->PushSprite("Resource/Roll/roll_side_%d.png", i);
	}

	playerUroll = new ZeroAnimation(6.0f);
	for (int i = 1; i <= 4; i++) {
		playerUroll->PushSprite("Resource/Roll/roll_back_%d.png", i);
	}
	
	playerDroll = new ZeroAnimation(6.0f);
	for (int i = 1; i <= 4; i++) {
		playerDroll->PushSprite("Resource/Roll/roll_front_%d.png", i);
	}

	/*-------------------------------------------------------------------------*/
	
	playerSattack = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		playerSattack->PushSprite("Resource/Attack/attack_side_%d.png", i);
	}

	playerUattack = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		playerUattack->PushSprite("Resource/Attack/attack_back_%d.png", i);
	}

	playerDattack = new ZeroAnimation(3.0f);
	for (int i = 1; i <= 2; i++) {
		playerDattack->PushSprite("Resource/Attack/attack_front_%d.png", i);
	}

	/*-------------------------------------------------------------------------*/


	ZeroSoundMgr->PushSound("Resource/Sound/Player/Player_attack.wav", "attackSound");
	ZeroSoundMgr->PushSound("Resource/Sound/Player/Player_ill.wav", "illSound");
	ZeroSoundMgr->PushSound("Resource/Sound/Player/Player_roll.wav", "rollSound");
	ZeroSoundMgr->PushSound("Resource/Sound/Player/Player_move.wav", "moveSound");

	ZeroSoundMgr->PushChannel("attackSound", "PlayerChannel", true);
	ZeroSoundMgr->PushChannel("illSound", "PlayerChannel", true);
	ZeroSoundMgr->PushChannel("rollSound", "PlayerChannel", true);
	ZeroSoundMgr->PushChannel("moveSound", "PlayerChannel", true);

	playerSrun->SetScalingCenter(playerSrun->Width() * 0.5f);
	playerSidle->SetScalingCenter(playerSidle->Width() * 0.5f);
	playerSroll->SetScalingCenter(playerSroll->Width() * 0.5f);
	playerSattack->SetScalingCenter(playerSattack->Width() * 0.5f);


	PushScene(playerSrun);
	PushScene(playerUrun);
	PushScene(playerDrun);

	PushScene(playerSidle);
	PushScene(playerUidle);
	PushScene(playerDidle);

	PushScene(playerSroll);
	PushScene(playerUroll);
	PushScene(playerDroll);

	PushScene(playerSattack);
	PushScene(playerUattack);
	PushScene(playerDattack);

	

	SetPos(600, 350);

	SetAbility(/*GameManager::GetInstance()->itemType*/ 6);
}

void PlayerCharacter::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	Move(eTime);
	Attack(eTime);
	Idle();

	if (health <= 90)
		isAlive = false;
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
	case RIGHTATTACK:
		playerSattack->Render();
		playerSattack->SetScale(-1, 1);
		break;
	case LEFTATTACK:
		playerSattack->Render();
		playerSattack->SetScale(1, 1);
		break;
	case UPATTACK:
		playerUattack->Render();
		break;
	case DOWNATTACK:
		playerDattack->Render();
		break;
	}


}

void PlayerCharacter::Move(float eTime)
{
	if (ZeroInputMgr->GetKey(VK_RIGHT) == INPUTMGR_KEYON) {
		if (Pos().x <= 1280 - (playerSrun->Width() * 2.5f) ) {
			AddPosX(speed * eTime);
			playerCondition = RIGHTRUN;

			prevKey = VK_RIGHT;
			isMove = true;

		}
		ZeroSoundMgr->PlayChannel("moveSound", "PlayerChannel");
	}
	else isMove = false;

	if (ZeroInputMgr->GetKey(VK_LEFT) == INPUTMGR_KEYON) {
		if (Pos().x >= playerSrun->Width() * 1.5f) {
			AddPosX(-speed * eTime);
			playerCondition = LEFTRUN;

			prevKey = VK_LEFT;
			isMove = true;

		}
		ZeroSoundMgr->PlayChannel("moveSound", "PlayerChannel");
	}

	if (ZeroInputMgr->GetKey(VK_UP) == INPUTMGR_KEYON) {
		if (Pos().y >= playerSrun->Height() - 100) {
			AddPosY(-speed * eTime);
			playerCondition = UPRUN;

			prevKey = VK_UP;
			isMove = true;

		}
		ZeroSoundMgr->PlayChannel("moveSound", "PlayerChannel");
	}

	if (ZeroInputMgr->GetKey(VK_DOWN) == INPUTMGR_KEYON) {
		if (Pos().y <= 720 - playerSrun->Height() * 2.1f) {
			AddPosY(speed * eTime);
			playerCondition = DOWNRUN;

			prevKey = VK_DOWN;
			isMove = true;

		}
		ZeroSoundMgr->PlayChannel("moveSound", "PlayerChannel");
	}

	if (ZeroInputMgr->GetKey('X') == INPUTMGR_KEYDOWN)
		isRoll = true;
	
	if (isRoll && stamina > 0) {
		rollTimer.first += eTime;

		speed = 250;
		ZeroSoundMgr->PlayChannel("rollSound", "PlayerChannel");

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

		if (rollTimer.first >= rollTimer.second) {
			isRoll = false;
			speed = defaultSpeed;
			stamina -= 20;
			rollTimer.first = 0;
		}
	}
}

void PlayerCharacter::Attack(float eTime)
{
	if (ZeroInputMgr->GetKey('Z') == INPUTMGR_KEYDOWN)
		isAttack = true;

	if (isAttack)
	{
		attackTimer.first += eTime;
		ZeroSoundMgr->PlayChannel("attackSound", "PlayerChannel");

		speed = 0;

		switch (prevKey)
		{
		case VK_RIGHT:
			playerCondition = RIGHTATTACK;
			break;
		case VK_LEFT:
			playerCondition = LEFTATTACK;
			break;
		case VK_UP:
			playerCondition = UPATTACK;
			break;
		case VK_DOWN:
			playerCondition = DOWNATTACK;
			break;
		}

		if (attackTimer.first >= attackTimer.second)
		{
			isAttack = false;
			speed = defaultSpeed;
			attackTimer.first = 0;
		}
	}
}

void PlayerCharacter::Idle()
{
	if (!isMove && !isAttack) 
	{
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

		if(stamina <= 100)
			stamina += 0.0001f;
	}
}

void PlayerCharacter::SetAbility(int type)
{
	switch (type)
	{
	case Item::ITEM::SHOES:
		speed = 150;
		defaultSpeed = speed;
		health = 100;
		defaultHealth = health;
		attackPower = 50;
		defaultDamage = attackPower;
		break;
	case Item::ITEM::DUMBBELL:
		speed = 100;
		defaultSpeed = speed;
		health = 150;
		attackPower = 1.3f;
		break;
	case Item::ITEM::ROCK:
		speed = 100;
		defaultSpeed = speed;
		health = 100;
		attackPower = 2.5f;
		break;
	case Item::ITEM::GLOVE:
		speed = 125;
		defaultSpeed = speed;
		health = 100;
		attackPower = 2.0f;
		break;
	case Item::ITEM::CLOAK:
		speed = 125;
		defaultSpeed = speed;
		health = 125;
		attackPower = 1.3f;
		break;
	case Item::ITEM::HELMET:
		speed = 100;
		defaultSpeed = speed;
		health = 125;
		attackPower = 2.0f;
		break;
	default:
		speed = 100;
		defaultSpeed = speed;
		health = 100;
		attackPower = 1.3f;
	}
}


/*
Çì¸£¸Þ½º ½Å¹ß [SPEED +2]
´ýº§ [HEALTH +2]
Â¯µ¹ [DAMAGE +2]
±Û·Îºê [DAMAGE +1 / SPEED +1]
¸ÁÅä [SPEED +1 / HEALTH +1]
Çï¸ä [HEALTH +1/DAMAGE +1]
*/