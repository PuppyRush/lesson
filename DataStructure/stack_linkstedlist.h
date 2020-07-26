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

//������ �� ���� �����Ѵ�.
int pop();

//������ ��� ���� �ʱ�ȭ�մϴ�.
void clear();

//�� ���� ���� �����ݴϴ�.
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

