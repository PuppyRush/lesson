#pragma once

#include <stdio.h>

//큐의 노드 갯수는 최고 MAX_VALUE갯수 만큼만 가능합니다.
#define MAX_VALUE 100

typedef struct WormNode
{
	int value;
	WormNode* next;
	WormNode* prev;
};

WormNode* head = NULL;
WormNode* tail = NULL;

//큐의 맨 마지막 노드에 새로운 노드를 추가하고 그 노드를 반환합니다.
WormNode* push_back(int value);

//큐의 맨 앞 노드를 반환합니다.
WormNode* pop();

//스택의 모든 노들들을 없앱니다.
void clear();

//큐의 맨 앞의 노드 값을 보여줍니다.
int front();

//큐의 노드중 value와 일치하는 노드를 찾아 제거하고 앞 뒤 노드의 관계를 다시 설정합니다.
//제거된 노드를 반환합니다.
WormNode* remove(int value);

//node의 뒤에 새로운 값을 추가합니다.v
void insert(WormNode* prev_node, WormNode* new_node);

//value와 일치하는 노드를 찾고 새로운 노드로 교체합니다.
//교체되는 노드를 반환합니다.
WormNode* replace(int value, WormNode* new_node);

//큐에서 value와 일치하는 노드를 찾아 반환합니다.
WormNode* find(int value);

int main()
{

	push_back(3);
	push_back(5);
	push_back(15);
	push_back(32);
	push_back(5);
	push_back(6);
	push_back(5125);
	pop();
	remove(5);
	remove(3);
	WormNode* node1 = remove(6);
	push_back(3);
	insert(find(6), node1);
	replace(5125, remove(32));

}

#pragma once
