#pragma once

#include "Unit.h"

class Board
{

public:
	Board(size_t height, size_t width);


private:
	size_t height;
	size_t width;

	Unit** board;

};

