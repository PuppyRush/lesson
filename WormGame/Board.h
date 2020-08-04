#pragma once

#include "Unit.h"
#include "Wall.h"
#include "Worm.h"
#include "Hurdle.h"
#include "Feed.h"

class Board
{

public:

	Board() = delete;
	Board(size_t height, size_t width);

	Unit* getUnit(size_t x, size_t y);

	void setUnit(Unit* unit);

	inline size_t getHeight()
	{
		return height;
	}

	inline size_t getWidth()
	{
		return width;
	}

private:

	//height와 width가 size_t인 이유는?
	size_t height;
	size_t width;

	//왜 삼중포인터로 board가 선언되었는지 생각해봅시다.
	Unit*** board;

};

