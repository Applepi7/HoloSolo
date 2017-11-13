#include "stdafx.h"
#include "MenuScene.h"

#include "ZeroSceneManager.h"

#include "FirstStage.h"
#include "CartoonScene.h"


MenuScene::MenuScene()
{
	background = new ZeroSprite("Resource/UI/Menu/background.png");

	startBtn = new ZeroSprite("Resource/UI/Menu/Button/ic_start_click.png");
	howtoBtn = new ZeroSprite("Resource/UI/Menu/Button/ic_howtoplay_click.png");
	prolBtn = new ZeroSprite("Resource/UI/Menu/Button/ic_prolog_click.png");


	PushScene(startBtn);
	PushScene(howtoBtn);
	PushScene(prolBtn);

	startBtn->SetPos(1000, 400);
	howtoBtn->SetPos(1000, 500);
	prolBtn->SetPos(1000, 600);
}	

void MenuScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	startBtn->Update(eTime);

	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
	{
		if (startBtn->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new FirstStage());
		}

		if (prolBtn->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new CartoonScene());
		}

	}
}

void MenuScene::Render()
{
	ZeroIScene::Render();

	background->Render();
	
	startBtn->Render();
	howtoBtn->Render();
	prolBtn->Render();
}

void MenuScene::ShowHowTo()
{
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
	{
		
	}
}