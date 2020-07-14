#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	
	int a = 10;
	printf("%p %d", &a, a); 

	//포인터의 사용
	int *ptr = &a;

	//이중포인터의 사용
	int** ptr2 = &ptr;

	//각 context의 연산에서 메모리에서 일어나는 일을 고려하여 무엇이 출력되는지 생각해보기.
	printf("%p %d", &a, a);
	printf("%p %p %d", &ptr, ptr, *ptr);
	printf("%p %p %p %d", &ptr2, ptr2, *ptr2, **ptr2);

	//32bit에서는 왜 램의 최대 용량이 4gb일까?
	//32bit에선 몇개의 주소 공간을 이론적으로 사용 가능할까?
}