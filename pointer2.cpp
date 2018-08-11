//#include <stdio.h>
//#include <memory>
//
//int main()
//{
//	int integerArray[10];
//	int *ptr = integerArray;
//
//	printf("%d\n", sizeof(ptr));
//
//	for (int i = 0; i < 10; i++)
//		integerArray[i] = i;
//
//	for (int i = 0; i < 10; i++)
//		printf("%d, %p\n", *(ptr + i), ptr + i);
//
//	//integerArray++;
//	ptr = integerArray;
//
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	printf("%d, %p\n", *ptr, ptr);
//	//	ptr++;
//	//}
//
//	int **ptr2 = &ptr;
//	printf("%p %p\n", ptr2, &ptr);
//
//
//	int ary2[10][10];
//	memset(ary2, 0, sizeof(int) * 10 * 10);
//
//	int number = 100;
//	for (int i = 0; i < 10; i++)
//		for (int l = 0; l < 10; l++)
//			ary2[i][l] = number++;
//
//	int *aryptr = ary2[3];
//	printf("%d %p", *aryptr, aryptr + 3);
//
//
//	ptr = integerArray;
//
//	int value = *ptr++;
//	value = (*ptr)++;
//	value = ++*ptr;
//	value = *++ptr;
//
//	//define
//
//	//const
//
//	//lvalue , rvalue
//
//	//malloc
//}