#include <stdio.h>


//1. �ݺ���/���ǹ�
// https://codeup.kr/problem.php?id=1358

//2. �迭
void array()
{
	int ary[5][5];
	int i = 0, l = 0, num = 0;
	for (; i < 5; i++)
	{
		for (; l < 5; l++)
		{
			ary[i][l] = num++;
		}
	}

	//��µǴ� ����?
	printf("%d", *(ary + 11)); 
	printf("%p, %p", ary, ary + 4);

	//3. ������
	//swap�Լ� �ϼ��ϱ�.
	swap(ary[3][1], ary[2][4]);
}


//4. ���ڿ�
void reverse(char *str, int length)
{
	//���ڿ��� ������ �˰��� �ۼ��ϱ�.
}
