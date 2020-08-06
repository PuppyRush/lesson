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

	//초기화는 멤버변수에서 즉시하거나 생성자 초기화 리스트에서 하거나 선택. 
	//초기화 리스트에서 초기화를 시도하면 멤버변수에서 초기화는 수행하지 않는다.
	//Worm은 자료구조 리스트를 이용하여 관리한다.	
	Unit* m_wormHead = nullptr;
	Unit* m_wormTail = nullptr;

	//나머지 Unit들은 어떻게 관리할것인가?
	
};

