#include "stdafx.h"
#include "Item.h"

#include "Random.h"

#include "GameManager.h"
#include "PlayerCharacter.h"


Item::Item() : type(RandomInt(0, 5))
{
	switch (type)
	{
	case SHOES:
		itemImage = new ZeroSprite("Resource/Item/shoes.png");
		break;
	case DUMBBELL:
		itemImage = new ZeroSprite("Resource/Item/dumbbell.png");
		break;
	case ROCK:
		itemImage = new ZeroSprite("Resource/Item/rock.png");
		break;
	case GLOVE:
		itemImage = new ZeroSprite("Resource/Item/glove.png");
		break;
	case CLOAK:
		itemImage = new ZeroSprite("Resource/Item/cloak.png");
		break;
	case HELMET:
		itemImage = new ZeroSprite("Resource/Item/helmet.png");
		break;
	}
	PushScene(itemImage);

	SetPos(640 - itemImage->Width() * 0.5f, 355 - itemImage->Height() * 0.5f);
}


void Item::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	itemImage->Update(eTime);
}

void Item::Render()
{
	ZeroIScene::Render();

	itemImage->Render();
}