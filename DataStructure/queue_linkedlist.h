#pragma once

#include <stdio.h>

//ť�� ��� ������ �ְ� MAX_VALUE���� ��ŭ�� �����մϴ�.
#define MAX_VALUE 100

typedef struct WormNode
{
	int value;
	WormNode* next;
	WormNode* prev;
};

WormNode* head = NULL;
WormNode* tail = NULL;

//ť�� �� ������ ��忡 ���ο� ��带 �߰��ϰ� �� ��带 ��ȯ�մϴ�.
WormNode* push(int value);

//ť�� �� �� ��带 ��ȯ�մϴ�.
WormNode* pop();

//������ ��� ������ ���۴ϴ�.
void clear();

//ť�� �� ���� ��� ���� �����ݴϴ�.
int front();

//ť�� ����� value�� ��ġ�ϴ� ��带 ã�� �����ϰ� �� �� ����� ���踦 �ٽ� �����մϴ�.
//���ŵ� ��带 ��ȯ�մϴ�.
WormNode* remove(int value);

//node�� �ڿ� ���ο� ���� �߰��մϴ�.v
void insert(WormNode* prev_node, WormNode* new_node);

//value�� ��ġ�ϴ� ��带 ã�� ���ο� ���� ��ü�մϴ�.
//��ü�Ǵ� ��带 ��ȯ�մϴ�.
WormNode* replace(int value, WormNode* new_node);

//ť���� value�� ��ġ�ϴ� ��带 ã�� ��ȯ�մϴ�.
WormNode* find(int value);

int main()
{

	push(3);
	push(5);
	push(15);
	push(32);
	push(5);
	push(6);
	push(5125);
	pop();
	remove(5);
	remove(3);
	WormNode* node1 = remove(6);
	push(3);
	insert(find(6), node1);
	replace(5125, remove(32));

}

#pragma once
