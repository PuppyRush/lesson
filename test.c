// test_Ap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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

	//x,y,b의 값은?
	printf("%d %d %d\n", x, y, b);
}

//2. 배열과 포인터
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

	//출력되는 값은? ary의 주소는 100이고 int type의 크기는 4byte라고 가정한다.
	printf("%d\n", (ary + 2));
	printf("%d\n", *(ary + 2));
	printf("%d\n", *(ary + 1) + 2);
	printf("%d\n", **(ary + 2));
	printf("%d\n", *(*(ary + 2) + 1));
	printf("%d, %d", ary, ary + 4);

	//3. 포인터
	//swap함수 완성하기.
	//swap(ary[3][1], ary[2][4]);
}


//4. 문자열
void reverse(char* str, int length)
{
	//문자열을 뒤집는 알고리즘 작성하기.
}


int main()
{
	prit();
	operator();
	array();

	return 0;

}

