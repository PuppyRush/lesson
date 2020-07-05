#include <stdio.h>
#include <memory>



int function(double a)
{
	return 1;
}

void set(int ary[10])
{

}

void call_by_ptr(int *ptr, int size)
{
	//ptr[1]...
}

int main()
{
	//const

	//lvalue , rvalue

	//malloc
	int *heap = (int *)malloc(sizeof(int) * 100);
	//heap[2] = 3;

	for (int i = 10; i < 20; i++)
		*(heap+i) = i;

	int cpy[10];
	memcpy(cpy, heap+10 , sizeof(int) * 10);

	free(heap);

	int(*funptr)(double a) = function;

	sizeof(double*);

	

	//heap, stack, code, data
}