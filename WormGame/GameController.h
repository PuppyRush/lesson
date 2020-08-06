#pragma once

#include <Windows.h>
#include "Board.h"

class GameController
{
public:

	GameController();

	//키를 받아서 적절하게 처리한다.
	void command(UINT key);

private:

	void goLeft();
	void goRight();
	void goTop();
	void goBottom();

	bool checkCollision();
	bool eatFeed();

private:

	Board m_board;

};

