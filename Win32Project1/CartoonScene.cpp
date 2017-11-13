#include "stdafx.h"
#include "CartoonScene.h"

#include "ZeroSceneManager.h"
#include "MenuScene.h"

#include <conio.h>

CartoonScene::CartoonScene() : index(1)
{
	page1 = new ZeroSprite("Resource/UI/Menu/Cartoon/cartoon_1.png");
	page2 = new ZeroSprite("Resource/UI/Menu/Cartoon/cartoon_2.png");
	page3 = new ZeroSprite("Resource/UI/Menu/Cartoon/cartoon_3.png");
	page4 = new ZeroSprite("Resource/UI/Menu/Cartoon/cartoon_4.png");

	PushScene(page1);
	PushScene(page2);
	PushScene(page3);
	PushScene(page4);
}


CartoonScene::~CartoonScene()
{
}

void CartoonScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (ZeroInputMgr->GetKey(VK_RIGHT) == INPUTMGR_KEYDOWN) {
		index += 1;
		if (index > 4)
		{
			PopScene(page1);
			PopScene(page2);
			PopScene(page3);
			PopScene(page4);

			ZeroSceneMgr->ChangeScene(new MenuScene());
		}
	}
}

void CartoonScene::Render()
{
	ZeroIScene::Render();

	switch (index)
	{
	case 1:
		page1->Render();
		break;
	case 2:
		page2->Render();
		break;
	case 3:
		page3->Render();
		break;
	case 4:
		page4->Render();
		break;
	}
}
