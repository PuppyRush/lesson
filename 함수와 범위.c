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


	//printf�� ���?
	//main�Լ� ȣ��
	//����Լ�.. (�Ǻ���ġ,factorial ������)
}