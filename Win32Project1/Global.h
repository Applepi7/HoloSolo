#pragma once

#include "stdafx.h"

int RandomInt(int min, int max)
{
	return rand() % (max - min) + 1;
}