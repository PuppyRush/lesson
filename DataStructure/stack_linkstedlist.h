#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	Node* next;
	Node* prev;
}Node;

Node* Top;

//������ �� ���� ���� �߰��Ѵ�.
Node* push(Node* a, int value)
{
	if (a == NULL)
	{
		a = (Node*)malloc(sizeof(Node));
		a->value = value;
		a->next = NULL;
		a->prev = NULL;
		Top = a;

		return a;
	}
	else
	{
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->next = NULL;
		temp->value = value;
		temp->prev = a;
		a->next = temp;
		Top = temp;
		return temp;
	}
}

//������ �� ���� �����Ѵ�.
Node* pop(Node* a)
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