#pragma once

#include <stdio.h>



//������ �� ���� ���� �߰��Ѵ�.
void push(int* ary, int value);

//������ �� ���� �����Ѵ�.
int pop();

//������ ��� ���� �ʱ�ȭ�մϴ�.
void clear();

//�� ���� ���� �����ݴϴ�.
int top();



int main()
{
	int array[1000];

	push(array, 5);
	push(array, 3);
	push(array, 4);
	pop();

	push(array, 4);
	top();

	clear();

}

