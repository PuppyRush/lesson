#include <stdio.h>

#define ARY1 10
#define ARY2 10

int main()
{

	int integerarray[10];
	printf("%d\n", sizeof(integerarray));
	printf("%d\n", sizeof(integerarray[0]));

	for (int i = 0; i < 10; i++)
		integerarray[i] = i;

	int* ptr = integerarray;
	for (int i = 0; i < 10; i++)
		printf("%d, %p %p", *(ptr + i), ptr + i);


	//integerarray++;
	ptr = integerarray;

	for (int i = 0; i < 10; i++)
	{
		printf("%d, %p\n", *ptr, ptr);
		ptr++;
	}

	ptr = integerarray;
	int** ptr2 = &ptr;
	printf("%p %p %d\n", ptr, &ptr, *ptr);
	printf("%p %p %p\n", ptr2, &ptr2, *ptr2);

	//memset
	int ary2[ARY1][ARY2];
	memset(ary2, 1, sizeof(int) * ARY1 * ARY2);

	int number = 100;
	for (int i = 0; i < 10; i++)
		for (int l = 0; l < 10; l++)
			ary2[i][l] = number++;

	int* aryptr = ary2[3];
	printf("%d\n", *(aryptr + 12));


	ptr = integerarray;

	int value = *ptr++;
	value = (*ptr)++;
	value = ++ * ptr;
	value = *++ptr;


}