#pragma once

#include "global.h"



//큐의 맨 앞 노드에 새로운 노드를 추가하고 그 노드를 반환합니다.
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

//큐의 맨 마지막 노드에 새로운 노드를 추가하고 그 노드를 반환합니다.
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


//리스트의 맨 뒤를 제거합니다.
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

//리스트의 맨 앞을 제거합니다.
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


//스택의 모든 노드들을 없앱니다.
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

//큐의 맨 앞의 노드 값을 보여줍니다.
Worm front()
{
	return g_wormHead->worm;
}

//큐의 노드중 value와 일치하는 노드를 찾아 제거하고 앞 뒤 노드의 관계를 다시 설정합니다.
//제거된 노드를 반환합니다.
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

//node의 뒤에 새로운 값을 추가합니다.v
void insert(WormNode* prev_node, WormNode* new_node)
{
	new_node->next = prev_node->next;
	new_node->prev = prev_node;
	prev_node->next = new_node;
	prev_node->next->prev = new_node;
}

//value와 일치하는 노드를 찾고 새로운 노드로 교체합니다.
//교체되는 노드를 반환합니다.
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

//큐에서 value와 일치하는 노드를 찾아 반환합니다.
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
