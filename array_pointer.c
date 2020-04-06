#include <stdio.h>

#define ARY1 100
#define ARY2 100

int main()
{
	int integerarray[10];
	int* ptr = integerarray;

	printf("%d\n", sizeof(ptr));

	for (int i = 0; i < 10; i++)
		integerarray[i] = i;

	for (int i = 0; i < 10; i++)
		printf("%d, %p\n", *(ptr + i), ptr + i);

	//integerarray++;
	ptr = integerarray;

	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d, %p\n", *ptr, ptr);
	//	ptr++;
	//}

	int** ptr2 = &ptr;
	printf("%p %p\n", ptr2, &ptr);

	//memset
	int ary2[ARY1][ARY2];
	memset(ary2, 1, sizeof(int) * ARY1 * ARY2);

	int number = 100;
	for (int i = 0; i < 10; i++)
		for (int l = 0; l < 10; l++)
			ary2[i][l] = number++;

	int* aryptr = ary2[3];
	printf("%d %p", *aryptr, aryptr + 3);


	ptr = integerarray;

	int value = *ptr++;
	value = (*ptr)++;
	value = ++ * ptr;
	value = *++ptr;
}