#include <cstdio>

// 1. main함수의 리턴값과 매개변수의 역할.

void pointer()
{
	int integerarray[10];
	int* ptr = integerarray;

	for (int i = 0; i < 10; i++)
		integerarray[i] = i;
	
	// 2. 출력되는 값?
	printf("%p %d\n", ptr+2, *(ptr+5));

	for (int i = 0; i < 10; i++)
	{
		printf("%d, %p\n", *ptr, ptr);
		ptr++;
	}

	int** ptr2 = &ptr;

	//3. 출력되는 값?
	printf("%p %p %d\n", ptr, &ptr, *ptr);
	printf("%p %p %p\n", ptr2, &ptr2, *ptr2);

	ptr = integerarray;

	//4 출력되는 값?
	printf("%d", (*ptr)++);

}

