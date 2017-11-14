#pragma once
#include "ZeroIScene.h"

#include "Item.h"

class GameManager
{
private:
	static GameManager* instance;

public:
	GameManager();
	~GameManager();

	static GameManager* GetInstance();

	int itemType;

};

