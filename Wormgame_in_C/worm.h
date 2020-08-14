#pragma once

#include <limits.h>
#include "data.h"
#include "define.h"

static const size_t INVALID_SIZE = UINT_MAX;

//메인 윈도우 핸들러
static HWND g_hwndWnd = NULL;
static HWND g_hwndProc = NULL;
//지렁이 자료구조를 위한 변수
static Worm* g_wormHead = NULL;
static Worm* g_wormTail = NULL;

//extern과 static의 차이?
//https://dojang.io/mod/page/view.php?id=690
static	size_t g_width = 0;
static	size_t g_height = 0;


void CALLBACK MyTimerProc(HWND hWnd, UINT nMsg, UINT_PTR nIDEvent, DWORD dwTime)
{
	// 함수가 호출될때 작업할 내용을 여기에 적으면 됩니다. 
	int a;
	a = 3;
}

static void init_game()
{
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
			g_map[i][l].coord.x = l;
			g_map[i][l].coord.y = i;
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
	g_map[h][w].coord.x = w;
	g_map[h][w].coord.y = h;

	g_wormTail = g_wormHead = (Worm*)malloc(sizeof(Worm));
	g_wormHead->coord.x = w;
	g_wormHead->coord.y = h;
	g_wormHead->order = eLeft;


}

static void timer()
{
	switch (g_wormHead->order)
	{
	case eLeft:
		g_wormHead->coord.x -= 1;
		break;
	case eRight:
		g_wormHead->coord.x += 1;
		break;
	case eDown:
		g_wormHead->coord.y += 1;
		break;
	case eUp:
		g_wormHead->coord.y -= 1;
		break;
	default:
		break;
	}
}

static void keydown(int key)
{
	switch (key)
	{
	case VK_LEFT:
		g_wormHead->order = eLeft;
		break;
	case VK_RIGHT:
		g_wormHead->order = eRight;
		break;
	case VK_UP:
		g_wormHead->order = eUp;
		break;
	case VK_DOWN:
		g_wormHead->order = eDown;
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