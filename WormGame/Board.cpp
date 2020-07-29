#include "Board.h"

Board::Board(size_t h, size_t w)
	:height(h), width(w), board(nullptr)
{
	board = new Unit** [height];

	for (int i = 0; i < h; i++)
	{
		board[i] = new Unit*[width];
		for (int l = 0; l < width; l++)
		{
			board[i][l] = new Unit{l,i};
		}

	} 
}

void Board::setUnit(Unit* unit)
{
	auto x = unit->getY();
	auto y = unit->getX();

	delete board[y][x];
	board[y][x] = unit;
}

Unit* Board::getUnit(size_t x, size_t y)
{
	return board[y][x];
}