#include <cstdio>

// 1. main�Լ��� ���ϰ��� �Ű������� ����.

void pointer()
{
	int integerarray[10];
	int* ptr = integerarray;

	for (int i = 0; i < 10; i++)
		integerarray[i] = i;
	
	// 2. ��µǴ� ��?
	printf("%p %d\n", ptr+2, *(ptr+5));

	for (int i = 0; i < 10; i++)
	{
		printf("%d, %p\n", *ptr, ptr);
		ptr++;
	}

	int** ptr2 = &ptr;

	//3. ��µǴ� ��?
	printf("%p %p %d\n", ptr, &ptr, *ptr);
	printf("%p %p %p\n", ptr2, &ptr2, *ptr2);

	ptr = integerarray;

	//4 ��µǴ� ��?
	printf("%d", (*ptr)++);

}

