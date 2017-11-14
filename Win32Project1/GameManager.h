#pragma once
#include "ZeroIScene.h"

#include "Item.h"

class GameManager
	: public ZeroIScene
{
private:
	static GameManager* instance;

public:
	GameManager();
	~GameManager();

	static GameManager* GetInstance();

	int itemType;

};

