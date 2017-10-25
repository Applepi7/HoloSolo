#pragma once

#include "stdafx.h"

#include "PlayerCharacter.h"
#include "Slime.h"

inline bool IsCollision(PlayerCharacter* player, Slime* slime)
{
	if (
		(player->Pos().x - slime->Pos().x <= slime->slimeMove->Width()) &&
		(slime->Pos().x - player->Pos().x <= player->playerSidle->Width()) &&
		(slime->Pos().y - player->Pos().y <= player->playerSidle->Height()) &&
		(player->Pos().y - slime->Pos().y <= slime->slimeMove->Height())
		)
		return true;
	else
		return false;
}