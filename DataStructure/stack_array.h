#pragma once

#include <stdio.h>



//������ �� ���� ���� �߰��Ѵ�.
void push_back(int* ary, int value);

//������ �� ���� �����Ѵ�.
int pop();

//������ ��� ���� �ʱ�ȭ�մϴ�.
void clear();

//�� ���� ���� �����ݴϴ�.
int top();



int main()
{
	int array[1000];

	push_back(array, 5);
	push_back(array, 3);
	push_back(array, 4);
	pop();

	push_back(array, 4);
	top();

	clear();

}

