#pragma once

#include <stdio.h>



//스택의 맨 위에 값을 추가한다.
void push_back(int* ary, int value);

//스택의 맨 위를 제거한다.
int pop();

//스택의 모든 값을 초기화합니다.
void clear();

//맨 위의 값을 돌려줍니다.
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

