#pragma once

#include <stdio.h>

typedef struct Node
{
	int value;
	Node* next;
	Node* prev;
};

Node* top = NULL;

void push(int value);

//스택의 맨 위를 제거한다.
int pop();

//스택의 모든 값을 초기화합니다.
void clear();

//맨 위의 값을 돌려줍니다.
int top();


int main()
{

	push(5);
	push(3);
	push(4);
	pop();

	push(4);
	top();

	clear();

}

