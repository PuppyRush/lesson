// test_Ap.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void print()
{
	// https://codeup.kr/problem.php?id=1358
}

void operator()
{
	int x = 0;
	int y = 10;
	if (x++ && --x)
	{
		y++;
	}

	int b = y++ - ++y;
	y = b++ - y;

	//x,y,b�� ����?
	printf("%d %d %d\n", x, y, b);
}

//2. �迭�� ������
void array()
{
	int ary[5][5];
	int i = 0, l = 0, num = 0;
	for (i = 0; i < 5; i++)
	{
		for (l = 0; l < 5; l++)
		{
			ary[i][l] = num++;
		}
	}

	//��µǴ� ����? ary�� �ּҴ� 100�̰� int type�� ũ��� 4byte��� �����Ѵ�.
	printf("%d\n", (ary + 2));
	printf("%d\n", *(ary + 2));
	printf("%d\n", *(ary + 1) + 2);
	printf("%d\n", **(ary + 2));
	printf("%d\n", *(*(ary + 2) + 1));
	printf("%d, %d", ary, ary + 4);

	//3. ������
	//swap�Լ� �ϼ��ϱ�.
	//swap(ary[3][1], ary[2][4]);
}


//4. ���ڿ�
void reverse(char* str, int length)
{
	//���ڿ��� ������ �˰��� �ۼ��ϱ�.
}


int main()
{
	prit();
	operator();
	array();

	return 0;

}

