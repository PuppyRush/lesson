#include <stdio.h>

int x = 15;

void plus()
{
	int x = 24;
	//?

	static int i = 5;
	//?
}

int main()
{

	int i = 0;

	for (int i = 0; i < 10; i++)
	{
		printf("%d", i);
	}

	printf("%d", i); //?


	{
		int i = 10;
	}


	//printf는 어디에?
	//main함수 호출
	//재귀함수.. (피보나치,factorial 만들어보기)


	//call by value 와 call by reference

}