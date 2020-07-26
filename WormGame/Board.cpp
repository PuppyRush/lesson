#include "Board.h"

Board::Board(size_t h, size_t w)
	:height(h), width(w), board(nullptr)
{
	board = new Unit * [height];

	for (int i = 0; i < h; i++)
	{
		board[i] = new Unit[width];
	} 
}