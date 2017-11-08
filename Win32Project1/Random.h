#pragma once

#include "stdafx.h"

int inline RandomInt(int min, int max)
{
	return rand() % (max - min + 1) + 1;
}