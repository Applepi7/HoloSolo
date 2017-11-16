#include "stdafx.h"
#include "GameManager.h"


GameManager* GameManager::instance = nullptr;

GameManager::GameManager() : itemType(6)
{
}


GameManager::~GameManager()
{
}

GameManager * GameManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new GameManager();
	}

	return instance;
}
