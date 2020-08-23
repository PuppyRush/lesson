#pragma once

#include "define.h"
#include "list.h"


static MapType checkNextStepCollisionInMap(Worm* worm)
{
	size_t y = worm->coord.y;
	size_t x = worm->coord.x;

	switch (worm->order)
	{
	case eLeft:
		x -= 1;
		break;
	case eRight:
		x += 1;
		break;
	case eDown:
		y += 1;
		break;
	case eUp:
		y -= 1;
		break;
	}

	if (y < 0 || y >= g_height || x == 0 || x >= g_width)
		return eOutOfMap;
	else if (y == 0 || y == g_height - 1 || x == 0 || x == g_width - 1)
		return eWall;
	return g_map[y][x].type;
}

static MapType checkNowCollisionInMap(Worm* worm)
{
	return g_map[worm->coord.y][worm->coord.x].type;
}

static Coord getRandomFeedCoord()
{
	Coord c;
	while (1)
	{
		c.x = ( rand() % (UNIT_WIDTH_SIZE-3))+2;
		c.y = ( rand() % (UNIT_HEIGHT_SIZE-3))+2;
		if (g_map[c.y][c.x].type == eNone)
			return c;
	}
}

static void SetCoordInMap(Worm* worm)
{
	switch (worm->order)
	{
	case eLeft:
		worm->coord.x -= 1;
		break;
	case eRight:
		worm->coord.x += 1;
		break;
	case eDown:
		worm->coord.y += 1;
		break;
	case eUp:
		worm->coord.y -= 1;
		break;
	default:
		//error
		break;
	}
	g_map[worm->coord.y][worm->coord.x].type = eWorm;
}

static BOOL compareCoord(Coord lhs, Coord rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

//�߰��� ��ü�� �������ʿ� ����. ��, ������ ������� �Ӹ��� �տ� �ϳ� �߰��� ����� ��ü������ �����ΰ�ó�� ���ϰ�.
static void CreepingWorm()
{
	if (g_wormSize == 0)
	{
		//error
		return;
	}

	if (g_wormSize == 1) {
		g_map[g_wormHead->worm.coord.y][g_wormHead->worm.coord.x].type = eNone;
		SetCoordInMap(&g_wormHead->worm);
	}
	else
	{
		//������ �����.
		g_map[g_wormTail->worm.coord.y][g_wormTail->worm.coord.x].type = eNone;
		if (g_wormTail->worm.coord.y == 0 || g_wormTail->worm.coord.y == g_height - 1 || g_wormTail->worm.coord.x == 0 || g_wormTail->worm.coord.x == g_width - 1)
		{
			g_wormTail->worm.coord.x = 1;
		}
		pop_back();

		//�Ӹ� �տ� ������ ���ο� ��ü�� �߰��Ѵ�.
		WormNode* old_head = g_wormHead;
		Worm new_worm;
		new_worm.order = old_head->worm.order;
		new_worm.coord = old_head->worm.coord;
		SetCoordInMap(&new_worm);

		push_front(new_worm);
	}
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
	
	//shuffle - ������ ���´�.
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
			worm.order = eLeft;
			worm.coord.x = x + 1;
			worm.coord.y = y;
			break;
		}
		else if (order == eRight && g_map[y][x + 1].type == eNone)
		{
			worm.order = eRight;
			worm.coord.x = x - 1;
			worm.coord.y = y;
			break;
		}
		else if (order == eUp && g_map[y-1][x].type == eNone)
		{
			worm.order = eUp;
			worm.coord.x = x;
			worm.coord.y = y+1;
			break;
		}
		else if (order == eDown && g_map[y+1][x].type == eNone)
		{
			worm.order = eDown;
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

	Worm worm;
	worm.coord.x = w;
	worm.coord.y = h;
	worm.order = eLeft;
	push_front(worm);

	g_feed = getRandomFeedCoord();
	g_map[g_feed.y][g_feed.x].type = eFeed;

}

static GameState BeforeMove()
{
	MapType type = checkNextStepCollisionInMap(&g_wormHead->worm);
	switch (type)
	{
	case eWall:
	case eOutOfMap:
	case eRock:
	case eWorm:
		return eWormDie;
	case eFeed:
	case eNone:
		return eOperating;
	default:
		return eError;
	}
}

static void AfterMove()
{
}

static void Moving()
{
	CreepingWorm();

	MapType type = checkNextStepCollisionInMap(&g_wormHead->worm);
	if (type == eFeed)
	{
		//���� ��ġ ������
		g_map[g_feed.y][g_feed.x].type = eNone;
		g_feed = getRandomFeedCoord();
		g_map[g_feed.y][g_feed.x].type = eFeed;

		Worm worm = getNewTail();
		push_back(worm);
		g_map[worm.coord.y][worm.coord.x].type = eWorm;
	}

	
}

static void timer()
{	
	GameState type = BeforeMove();
	
	if (type == eOperating)
	{
		Moving();
		AfterMove();
	}
	else if (type == eWormDie || type == eError)
	{

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