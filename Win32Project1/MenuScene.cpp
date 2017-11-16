#include "stdafx.h"
#include "MenuScene.h"

#include "ZeroSceneManager.h"

#include "FirstStage.h"
#include "CartoonScene.h"


MenuScene::MenuScene() : page(0), isStart(false), isStartPress(false), isHowToPress(false), isProlPress(false)
{
	background = new ZeroSprite("Resource/UI/Menu/background.png");

	startBtn = new ZeroSprite("Resource/UI/Menu/Button/ic_start_click.png");
	startBtnPress = new ZeroSprite("Resource/UI/Menu/Button/ic_start_press.png");
	howtoBtn = new ZeroSprite("Resource/UI/Menu/Button/ic_howtoplay_click.png");
	howtoBtnPress = new ZeroSprite("Resource/UI/Menu/Button/ic_howtoplay_press.png");
	prolBtn = new ZeroSprite("Resource/UI/Menu/Button/ic_prolog_click.png");
	prolBtnPress = new ZeroSprite("Resource/UI/Menu/Button/ic_prolog_press.png");

	howToPage1 = new ZeroSprite("Resource/UI/Menu/HowTo/bg_htp_1.jpg");
	howToPage2 = new ZeroSprite("Resource/UI/Menu/HowTo/bg_htp_2.jpg");

	nextPageBtn = new ZeroSprite("Resource/UI/Menu/HowTo/ic_next.png");
	prevPageBtn = new ZeroSprite("Resource/UI/Menu/HowTo/ic_prev.png");
	startGameBtn = new ZeroSprite("Resource/UI/Menu/HowTo/ic_start.png");

	PushScene(startBtn);
	PushScene(startBtnPress);
	PushScene(howtoBtn);
	PushScene(howtoBtnPress);
	PushScene(prolBtn);
	PushScene(prolBtnPress);

	startBtn->SetPos(1000, 400);
	startBtnPress->SetPos(1000, 400);
	howtoBtn->SetPos(1000, 500);
	howtoBtnPress->SetPos(1000, 500);
	prolBtn->SetPos(1000, 600);
	prolBtnPress->SetPos(1000, 600);

	nextPageBtn->SetPos(975, 360);
	prevPageBtn->SetPos(250, 360);
	startGameBtn->SetPos(975, 360);
}	

void MenuScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
	{
		if (startBtn->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new FirstStage());
		}


		if (prolBtn->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new CartoonScene());
			isProlPress = true;
		}
		else
			isProlPress = false;

	}

	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYON)
	{
		if (startBtn->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			isStartPress = true;
		}
		else
			isStartPress = false;
	
		if (howtoBtn->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			isHowToPress = true;
		}
		else
			isHowToPress = false;

		if (prolBtn->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			isProlPress = true;
		}
		else
			isProlPress = false;
	}

	ShowHowTo();

	printf("%d\n", page);
}

void MenuScene::Render()
{
	ZeroIScene::Render();

	background->Render();
	
	if (!isStartPress)
		startBtn->Render();
	else
		startBtnPress->Render();
	
	if (!isHowToPress)
		howtoBtn->Render();
	else
		howtoBtnPress->Render();

	if (!isProlPress)
		prolBtn->Render();
	else
		prolBtnPress->Render();

	switch (page)
	{
	case 1:
		howToPage1->Render();
		prevPageBtn->Render();
		nextPageBtn->Render();
		break;
	case 2:
		howToPage2->Render();
		prevPageBtn->Render();
		startGameBtn->Render();
		break;
	}
}

void MenuScene::ShowHowTo()
{

	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
	{
		if (howtoBtn->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			page = 1;
		}

		if (nextPageBtn->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			page = 2;
		}

		if (prevPageBtn->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			page -= 1;
			isStart = false;
		}

		if (startGameBtn->IsOverlapped(ZeroInputMgr->GetClientPoint()) && isStart)
		{
			ZeroSceneMgr->ChangeScene(new FirstStage());
		}
	}

	if (page == 2)
		isStart = true;
}