#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//인수로 전달할 Data의 크기가 매우 큰 경우에 인수전달 효율을 높일 수 있다 , 리스트
//배열 첨자연산은 본질적으로 Pointer 연산이다.
//void ptr?
//함수포인터

int main()
{
	
	//포인터 만들어보기
	int a = 10;
	printf("%x", &a); 

	int *ptr = &a;
	//ptr = ?
	//*ptr = ?

	int *ptr2 = NULL;
	//ptr2 = ?
	//*ptr2 = ?

	int** ptr3 = NULL; //**의 사용?
	
	//32bit에서 왜 4gb만 사용 가능?
	//32bit에선 몇개의 주소 공간이 사용 가능할까

}