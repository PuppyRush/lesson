#include <stdio.h>


//1. 반복문/조건문
// https://codeup.kr/problem.php?id=1358

//2. 배열
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

	//출력되는 값은?
	printf("%d", *(ary + 11)); 
	printf("%p, %p", ary, ary + 4);

	//3. 포인터
	//swap함수 완성하기.
	swap(ary[3][1], ary[2][4]);
}


//4. 문자열
void reverse(char *str, int length)
{
	//문자열을 뒤집는 알고리즘 작성하기.
}
