#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct WormNode
{
	int value;
	WormNode* next;
	WormNode* prev;
}WormNode;

WormNode* Top;

//������ �� ���� ���� �߰��Ѵ�.
WormNode* push(WormNode* a, int value)
{
	if (a == NULL)
	{
		a = (WormNode*)malloc(sizeof(WormNode));
		a->value = value;
		a->next = NULL;
		a->prev = NULL;
		Top = a;

		return a;
	}
	else
	{
		WormNode* temp = (WormNode*)malloc(sizeof(WormNode));
		temp->next = NULL;
		temp->value = value;
		temp->prev = a;
		a->next = temp;
		Top = temp;
		return temp;
	}
}

//������ �� ���� �����Ѵ�.
WormNode* pop(WormNode* a)
{
	if (a == NULL)
	{
	}
	else
	{
		if (a->prev != NULL)
		{
			a->prev->next = NULL;
			Top = a->prev;
		}
		free(a);
	}
	return 0;
}

int main()
{

	push(Top, 5);
	push(Top, 3);
	push(Top, 4);
	pop(Top);
	push(Top, 4);

}