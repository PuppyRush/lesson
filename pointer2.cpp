//#include <stdio.h>
//#include <memory>
//
//void set(int ary[10])
//{
//
//}
//
//void call_by_ptr(int *ptr, int size)
//{
//	//ptr[1]...
//}
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
//	//memset
//	int ary2[10][10];
//	memset(ary2, 1, sizeof(int) * 10 * 10);
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
//	int *heap = (int *)malloc(sizeof(int) * 100);
//	heap[2] = 3;
//
//	for (int i = 10; i < 20; i++)
//		*(heap+i) = i;
//
//	int cpy[10];
//	memcpy(cpy, heap+10 , sizeof(int) * 10);
//
//	free(heap);
//
//	
//
//
//	//heap, stack, Code, Data
//}