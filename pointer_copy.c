#pragma once

#include <stdlib.h>
#include <memory.h>
#include <time.h>

int* copy(int* ptr, size_t len)
{
	const size_t size = sizeof(int) * len;
	int* new_ary = (int*)malloc(size);

	//memcpy를 이용한 메모리 복사
	memcpy_s(new_ary, size, ptr, size);

	//반복문을 이용한 복사
	//for (int i = 0; i < len; i++)
	//{
	//	new_ary[i] = ptr[i];
	//}

	return new_ary;
}

int main()
{
	//case1
	int ary[10000];
	for (int i = 0; i < 10000; i++)
	{
		ary[i] = rand();
	}

	int* ptr = copy(ary, 10000);
	free(ptr);

	//case2
	int* ary2 = (int*)malloc(sizeof(int) * 10000);
	for (int i = 0; i < 10000; i++)
	{
		ary2[i] = rand();
	}

	int* ptr2 = copy(ary2, 10000);
	free(ptr2);
	free(ary2);
}