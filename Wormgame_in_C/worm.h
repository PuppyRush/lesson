#pragma once

#include <limits.h>
#include "define.h"
#include "list.h"

static const size_t INVALID_SIZE = UINT_MAX;

//메인 윈도우 핸들러
static HWND g_hwndWnd = NULL;
static HWND g_hwndProc = NULL;

//extern과 static의 차이?
//https://dojang.io/mod/page/view.php?id=690
static	size_t g_width = 0;
static	size_t g_height = 0;

static Coord g_feed;

static Coord getRandomCoord()
{
	Coord c;
	c.x = ( rand() % (UNIT_WIDTH_SIZE-2))+1;
	c.y = ( rand() % (UNIT_HEIGHT_SIZE-2))+1;
	return c;
}

static void SetCoordInMap(Coord coord, Type t)
{
	g_map[coord.y][coord.x].type = t;
}

static BOOL compareCoord(Coord lhs, Coord rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

static Worm getNewTail()
{
	Worm worm;
	size_t y = g_wormTail->worm.coord.y;
	size_t x = g_wormTail->worm.coord.x;

	if (g_map[y + 1][x].type != eNone && g_map[y - 1][x].type != eNone && g_map[y][x - 1].type != eNone && g_map[y][x + 1].type != eNone)
	{
		worm.coord.y = INVALID_VALUE;
		worm.coord.x = INVALID_VALUE;
		return worm;
	}
	
	//shuffle - 순서를 섞는다.
	int rnd[eOrder] = { eLeft, eRight, eDown, eUp };
	for (int i = 0; i < 5; i++)
	{
		char lhs = rand() % eOrder;
		char rhs = rand() % eOrder;
		char tmp = rnd[lhs];
		rnd[lhs] = rnd[rhs];
		rnd[rhs] = tmp;
	}

	for(int i=0 ; i < eOrder ; i++)
	{
		size_t order = rnd[i];
		
		if (order == eLeft && g_map[y][x-1].type == eNone)
		{
			worm.order = eRight;
			worm.coord.x = x + 1;
			worm.coord.y = y;
			break;
		}
		else if (order == eRight && g_map[y][x + 1].type == eNone)
		{
			worm.order = eLeft;
			worm.coord.x = x - 1;
			worm.coord.y = y;
			break;
		}
		else if (order == eUp && g_map[y-1][x].type == eNone)
		{
			worm.order = eDown;
			worm.coord.x = x;
			worm.coord.y = y+1;
			break;
		}
		else if (order == eDown && g_map[y+1][x].type == eNone)
		{
			worm.order = eUp;
			worm.coord.x = x;
			worm.coord.y = y-1;
			break;
		}
	}

	return worm;
}

static void init_game()
{
	srand((unsigned int)time(NULL));

	g_width = UNIT_WIDTH_SIZE;
	g_height = UNIT_HEIGHT_SIZE;

	//1.2차원 배열인 g_map을 동적 할당을 이용하여 초기화(height,width 크기에 맞추어)
	//2. 지렁이의 초기화. (자료구조 리스트를 이용, 지난 과제 소스를 이용)
	
	g_map = (Map**)malloc(sizeof(Map*) * g_height);
	if (g_map == NULL)
	{
		//exception
	}

	for (int i = 0; i < g_height; i++)
	{
		g_map[i] = (Map*)malloc(sizeof(Map)*g_width);
		if (g_map[i] == NULL)
		{
			//exception
		}
		for (int l = 0; l < g_width; l++)
		{
			g_map[i][l].type = eNone;
		}
	}

	//벽 체우기
	int h = 0;
	for (int w = 0; w < g_width; w++)
	{
		g_map[h][w].type = eWall;
	}

	h = g_height - 1;
	for (int w = 0; w < g_width; w++)
	{
		g_map[h][w].type = eWall;
	}

	int w = 0;
	for (int h = 0; h < g_height ; h++)
	{
		g_map[h][w].type = eWall;
	}

	w = g_width - 1;
	for (int h = 0; h < g_height; h++)
	{
		g_map[h][w].type = eWall;
	}

	//지렁이 초기화
	h = g_height / 2;
	w = g_width / 2;
	g_map[h][w].type = eWorm;

	g_wormTail = g_wormHead = (Worm*)malloc(sizeof(Worm));
	g_wormHead->worm.coord.x = w;
	g_wormHead->worm.coord.y = h;
	g_wormHead->worm.order = eLeft;
	g_wormHead->prev = NULL;
	g_wormHead->next = NULL;

	g_feed = getRandomCoord();
	g_map[g_feed.y][g_feed.x].type = eFeed;
}

static void timer()
{
	g_map[g_wormHead->worm.coord.y][g_wormHead->worm.coord.x].type = eNone;
	switch (g_wormHead->worm.order)
	{
	case eLeft:
		if (g_wormHead->worm.coord.x == 0 )
		{
		}
		else
		{
			g_map[g_wormHead->worm.coord.y][g_wormHead->worm.coord.x - 1].type = eWorm;
			g_wormHead->worm.coord.x -= 1;
		}

		break;
	case eRight:
		if (g_wormHead->worm.coord.x == g_width - 1 )
		{
		}
		else
		{
			g_map[g_wormHead->worm.coord.y][g_wormHead->worm.coord.x + 1].type = eWorm;
			g_wormHead->worm.coord.x += 1;
		}

		break;
	case eDown:
		if (g_wormHead->worm.coord.y == g_height - 1)
		{
		}
		else
		{
			g_map[g_wormHead->worm.coord.y + 1][g_wormHead->worm.coord.x].type = eWorm;
			g_wormHead->worm.coord.y += 1;
		}

		break;
	case eUp:
		if (g_wormHead->worm.coord.x == 0 )
		{
		}
		else
		{
			g_map[g_wormHead->worm.coord.y - 1][g_wormHead->worm.coord.x].type = eWorm;
			g_wormHead->worm.coord.y -= 1;
		}

		break;
	default:
		break;
	}

	WormNode* node = g_wormTail;
	while (node != NULL && node->prev != NULL)
	{
		g_map[node->worm.coord.y][node->worm.coord.x].type = eNone;
		if (node->worm.order == eLeft)
		{
			node->worm.coord.x -= 1;
			g_map[node->worm.coord.y][node->worm.coord.x-1].type = eWorm;
		}
		else if (node->worm.order == eRight)
		{
			node->worm.coord.x += 1;
			g_map[node->worm.coord.y][node->worm.coord.x + 1].type = eWorm;
		}
		else if (node->worm.order == eDown)
		{
			node->worm.coord.y += 1;
			g_map[node->worm.coord.y+1][node->worm.coord.x].type = eWorm;
		}
		else if (node->worm.order == eUp)
		{
			node->worm.coord.y -= 1;
			g_map[node->worm.coord.y-1][node->worm.coord.x].type = eWorm;
		}

		node = node->prev;
	}

	if (compareCoord(g_wormTail->worm.coord, g_feed))
	{

		//g_map[g_feed.y][g_feed.x].type = eNone;
		g_feed = getRandomCoord();
		g_map[g_feed.y][g_feed.x].type = eFeed;

		Worm worm = getNewTail();
		push(worm);
		g_map[worm.coord.y][worm.coord.x].type = eWorm;
	}

}

static void keydown(int key)
{
	switch (key)
	{
	case VK_LEFT:
		g_wormHead->worm.order = eLeft;
		break;
	case VK_RIGHT:
		g_wormHead->worm.order = eRight;
		break;
	case VK_UP:
		g_wormHead->worm.order = eUp;
		break;
	case VK_DOWN:
		g_wormHead->worm.order = eDown;
		break;
	}

}

static void finalize()
{

}

//반복되는 기능과 소스는 함수로 만드는것이 좋다.

//좌표 x를 입력받아 맵에서 Left위치를 반환한다.
static size_t getLeftInMap(const size_t x)
{
	//조건 검사
	if (x >= UNIT_WIDTH_SIZE)
	{
		//exception
		return INVALID_SIZE;
	}

	return MAP_LEFT + UNIT_WIDTH_LEN * x;
}

static size_t getTopInMap(const size_t y)
{
	//조건 검사
	if (y >= UNIT_HEIGHT_SIZE)
	{
		//exception
		return INVALID_SIZE;
	}

	return MAP_TOP + UNIT_HEIGHT_LEN * y;
}