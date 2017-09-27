#include "stdafx.h"
#include "Slime.h"


Slime::Slime()
{
	slime = new ZeroAnimation(1.5f);
	for (int i = 1; i <= 3; i++) {
		slime->PushSprite("Resource/Enemy/Slime/slime_front_%d.png", i);
	}
	PushScene(slime);
}


Slime::~Slime()
{
}

void Slime::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	
	slime->Update(eTime);

}

void Slime::Render()
{
	ZeroIScene::Render();

	slime->Render();
}
