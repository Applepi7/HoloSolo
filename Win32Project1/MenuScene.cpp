#include "stdafx.h"
#include "MenuScene.h"

#include "ZeroSceneManager.h"
#include "FirstStage.h"

MenuScene::MenuScene()
{
	btn = new ZeroSprite("Resource/UI/Button/bt_gamestart_click.png");
	PushScene(btn);

	btn->SetPos(500, 500);
}


MenuScene::~MenuScene()
{
}

void MenuScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	btn->Update(eTime);

	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP) {
		if (btn->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new FirstStage());
		}
	}
}

void MenuScene::Render()
{
	ZeroIScene::Render();
	btn->Render();
}
