#pragma once

#include <Windows.h>
#include "Board.h"

class GameController
{
public:

	GameController();

	//Ű�� �޾Ƽ� �����ϰ� ó���Ѵ�.
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

