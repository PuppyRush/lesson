#pragma once

#include "global.h"



//ť�� �� �� ��忡 ���ο� ��带 �߰��ϰ� �� ��带 ��ȯ�մϴ�.
WormNode* push_front(Worm worm)
{
	if (g_wormHead == NULL)
	{
		g_wormHead = (WormNode*)malloc(sizeof(WormNode));
		g_wormHead->worm = worm;
		g_wormHead->next = g_wormTail;
		g_wormHead->prev = NULL;
		g_wormTail = g_wormHead;
		g_wormSize = 1;
		return g_wormTail;
	}
	else
	{
		WormNode* new_node = (WormNode*)malloc(sizeof(WormNode));
		new_node->worm = worm;
		new_node->next = g_wormHead;
		new_node->prev = NULL;
		g_wormHead->prev = new_node;
		g_wormHead = new_node;
		g_wormSize++;
		return g_wormTail;
	}
}

//ť�� �� ������ ��忡 ���ο� ��带 �߰��ϰ� �� ��带 ��ȯ�մϴ�.
WormNode* push_back(Worm worm)
{
	if (g_wormTail == NULL)
	{
		g_wormHead = (WormNode*)malloc(sizeof(WormNode));
		g_wormHead->worm = worm;
		g_wormHead->next = g_wormTail;
		g_wormHead->prev = NULL;
		g_wormTail = g_wormHead;
		g_wormSize = 1;
		return g_wormTail;
	}
	else
	{
		WormNode* new_node = (WormNode*)malloc(sizeof(WormNode));
		new_node->worm = worm;
		new_node->next = NULL;
		new_node->prev = g_wormTail;
		g_wormTail->next = new_node;
		g_wormTail = new_node;
		g_wormSize++;
		return g_wormTail;
	}
}


//����Ʈ�� �� �ڸ� �����մϴ�.
WormNode* pop_back()
{
	if (g_wormHead == NULL)
	{

	}
	else if (g_wormHead == g_wormTail)
	{
		free(g_wormHead);
		g_wormSize = 0;
	}
	else
	{
		WormNode* old_tail = g_wormTail;
		g_wormTail->prev->next = NULL;
		g_wormTail = g_wormTail->prev;
		free(old_tail);
		g_wormSize--;
	}
}

//����Ʈ�� �� ���� �����մϴ�.
WormNode* pop_front()
{
	if (g_wormHead == NULL)
	{

	}
	else if (g_wormHead == g_wormTail)
	{
		free(g_wormHead);
		g_wormSize = 0;
	}
	else
	{
		WormNode* old_head = g_wormHead;
		g_wormHead->next->prev = NULL;
		g_wormHead = g_wormHead->next;
		free(old_head);
		g_wormSize--;
	}
}


//������ ��� ������ ���۴ϴ�.
void clear()
{
	WormNode* free_Node = g_wormHead;
	while (free_Node)
	{
		free(free_Node);
		free_Node = free_Node->next;
	}
	g_wormSize = 0;
}

//ť�� �� ���� ��� ���� �����ݴϴ�.
Worm front()
{
	return g_wormHead->worm;
}

//ť�� ����� value�� ��ġ�ϴ� ��带 ã�� �����ϰ� �� �� ����� ���踦 �ٽ� �����մϴ�.
//���ŵ� ��带 ��ȯ�մϴ�.
WormNode* remove_(Worm worm)
{
	WormNode* search = g_wormHead;
	WormNode* save = NULL;

	while (search)
	{
		if (search->worm.coord.x  == worm.coord.x && search->worm.coord.y == worm.coord.y)
		{
			save = search;
			if (search->prev == NULL)
			{
				g_wormHead = g_wormHead->next;
				g_wormHead->prev = NULL;
			}
			else if (search->next == NULL)
			{
				g_wormTail = g_wormTail->prev;
				g_wormTail->next = NULL;
			}
			else
			{
				search->next->prev = search->prev;
				search->prev->next = search->next;
			}
			free(search);
			g_wormSize--;
			break;
		}
		search = search->next;
	}
	return save;
}

//node�� �ڿ� ���ο� ���� �߰��մϴ�.v
void insert(WormNode* prev_node, WormNode* new_node)
{
	new_node->next = prev_node->next;
	new_node->prev = prev_node;
	prev_node->next = new_node;
	prev_node->next->prev = new_node;
}

//value�� ��ġ�ϴ� ��带 ã�� ���ο� ���� ��ü�մϴ�.
//��ü�Ǵ� ��带 ��ȯ�մϴ�.
WormNode* replace(int value, WormNode* wormnode)
{
	WormNode* search = g_wormHead;
	WormNode* save;

	while (search)
	{
		if (search->worm.coord.x == wormnode->worm.coord.x && search->worm.coord.y == wormnode->worm.coord.y)
		{
			save = search;
			search = wormnode;
			return save;
		}
		search = search->next;
	}
}

//ť���� value�� ��ġ�ϴ� ��带 ã�� ��ȯ�մϴ�.
WormNode* find(Worm worm)
{
	WormNode* search = g_wormHead;
	while (1)
	{
		if (search->worm.coord.x == worm.coord.x && search->worm.coord.y == worm.coord.y)
		{
			return search;
		}
		search = search->next;
	}
}
