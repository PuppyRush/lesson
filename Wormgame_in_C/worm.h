#pragma once

#include <limits.h>

#define DEFAULTS_SIZE UINT_MAX
#define MAP_HEIGHT 20
#define MAP_WIDTH 20 
#define TIMER_ID 1000


typedef enum Type
{
	eWall,
	eFeed,
	eWorm,
	eRock,
	eNone,
}Type;

typedef enum Order
{
	eLeft,
	eRight,
	eUp,
	eDown
}Order;

typedef struct Worm
{
	size_t x;
	size_t y;
	Order order;
}Worm;

static HWND g_hwndWnd = NULL;

static Worm* g_wormHead = NULL;
static Worm* g_wormTail = NULL;



//extern과 차이?
//https://dojang.io/mod/page/view.php?id=690
static	size_t g_width = DEFAULTS_SIZE;
static	size_t g_height = DEFAULTS_SIZE;

typedef struct Map
{
	Type type;
}Map;

Map** g_map;

static void init_game()
{
	g_width = MAP_WIDTH;
	g_height = MAP_HEIGHT;

	//1.2차원 배열인 g_map을 동적 할당을 이용하여 초기화(height,width 크기에 맞추어)
	//2. 지렁이의 초기화. (자료구조 리스트를 이용, 지난 과제 소스를 이용)
	
	//Timer 지정
	//Timer를 이용하여 주기적으로 처리해야할 일을 수행한다.
	//http://www.tipssoft.com/bulletin/board.php?bo_table=FAQ&wr_id=2192
	SetTimer(g_hwndWnd, TIMER_ID, 1000, NULL);
}


static void finalize()
{

}