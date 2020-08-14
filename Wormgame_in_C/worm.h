#pragma once

#include <limits.h>
#include "data.h"
#include "define.h"

static const size_t INVALID_SIZE = UINT_MAX;

//���� ������ �ڵ鷯
static HWND g_hwndWnd = NULL;
static HWND g_hwndProc = NULL;
//������ �ڷᱸ���� ���� ����
static Worm* g_wormHead = NULL;
static Worm* g_wormTail = NULL;

//extern�� static�� ����?
//https://dojang.io/mod/page/view.php?id=690
static	size_t g_width = 0;
static	size_t g_height = 0;


void CALLBACK MyTimerProc(HWND hWnd, UINT nMsg, UINT_PTR nIDEvent, DWORD dwTime)
{
	// �Լ��� ȣ��ɶ� �۾��� ������ ���⿡ ������ �˴ϴ�. 
	int a;
	a = 3;
}

static void init_game()
{
	g_width = UNIT_WIDTH_SIZE;
	g_height = UNIT_HEIGHT_SIZE;

	//1.2���� �迭�� g_map�� ���� �Ҵ��� �̿��Ͽ� �ʱ�ȭ(height,width ũ�⿡ ���߾�)
	//2. �������� �ʱ�ȭ. (�ڷᱸ�� ����Ʈ�� �̿�, ���� ���� �ҽ��� �̿�)
	
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

	//�� ü���
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

	//������ �ʱ�ȭ
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

//�ݺ��Ǵ� ��ɰ� �ҽ��� �Լ��� ����°��� ����.

//��ǥ x�� �Է¹޾� �ʿ��� Left��ġ�� ��ȯ�Ѵ�.
static size_t getLeftInMap(const size_t x)
{
	//���� �˻�
	if (x >= UNIT_WIDTH_SIZE)
	{
		//exception
		return INVALID_SIZE;
	}

	return MAP_LEFT + UNIT_WIDTH_LEN * x;
}

static size_t getTopInMap(const size_t y)
{
	//���� �˻�
	if (y >= UNIT_HEIGHT_SIZE)
	{
		//exception
		return INVALID_SIZE;
	}

	return MAP_TOP + UNIT_HEIGHT_LEN * y;
}