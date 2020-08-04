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

	//height�� width�� size_t�� ������?
	size_t height;
	size_t width;

	//�� ���������ͷ� board�� ����Ǿ����� �����غ��ô�.
	Unit*** board;

};

