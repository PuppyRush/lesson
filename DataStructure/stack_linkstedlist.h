#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	Node* next;
	Node* prev;
}Node;

Node* Head;
Node* Top;

//스택의 맨 위에 값을 추가한다.
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

//스택의 맨 위를 제거한다.
Node* pop(Node* a)
{
	if (a == NULL)
	{
	}
	else
	{
		a->prev->next = NULL;
		Top = a->prev;
		free(a);
	}
	return 0;
}

int main()
{

	push(Head, 5);
	push(Head, 3);
	push(Top, 4);
	pop(Head);

	push(Top, 4);

}