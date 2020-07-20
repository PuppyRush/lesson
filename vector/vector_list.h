#include <stdio.h>

const size_t FULL_SIZE = 1000;
List* queue = NULL;
List* head = NULL;
List* tail = NULL;

typedef struct List
{
	int data;
	List* rear;
	List* front;
};


//새로운 데이터를 q에 추가하고 새로운 노드를 반환한다.
List* enque(List* q, int data)
{

}

//q에서 노드를 제거하고 그 노드를 반환한다.
List* deque(List* q)
{

}

//q에서 dest에 해당하는 값을 갖는 노드가 있으면 해당 노드를 반환하고 존재하지 않으면 NULL을 반환한다.
List* find(List* q, int dest)
{

}

//q의 크기를 반환한다.
size_t size(List* q)
{

}

//q의 노드를 오름차순으로 정렬한다.
void sort()
{

}
