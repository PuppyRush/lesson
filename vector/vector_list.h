#include <stdio.h>


typedef struct List
{
	int data;
	List* rear;
	List* front;
};

const size_t FULL_SIZE = 1000;
List* queue = NULL;
List* head = NULL;
List* tail = NULL;

//queue ������ �ʱ�ȭ �Ѵ�.
void init()
{
	//queue, head, tail�� �ʱ�ȭ�Ѵ�.
}

//���ο� �����͸� q�� �߰��ϰ� ���ο� ��带 ��ȯ�Ѵ�.
List* enque(List* q, int data)
{

}

//q���� ��带 �����ϰ� �� ��带 ��ȯ�Ѵ�.
List* deque(List* q)
{

}

//q���� dest�� �ش��ϴ� ���� ���� ��尡 ������ �ش� ��带 ��ȯ�ϰ� �������� ������ NULL�� ��ȯ�Ѵ�.
List* find(List* q, int dest)
{

}

//q�� ũ�⸦ ��ȯ�Ѵ�.
size_t size(List* q)
{

}

//q�� ��带 ������������ �����Ѵ�.
void sort()
{

}


int main()
{
	init();
	enque(queue, 5);
	enque(queue, 10);
	enque(queue, 100);
	deque(queue);
	enque(queue, 4);
	enque(queue, 40);
	find(queue,10);
	printf("%d", size(queue));

	sort();
}
