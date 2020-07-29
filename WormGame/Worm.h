#pragma once

#include "Unit.h"

class Worm : public Unit
{
public:
	Worm(size_t x, size_t y);

	void MoveLeft();
	void MoveRight();
	void MoveDown();
	void MoveUp();
};

