#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

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

	
	//32bit에서 왜 4gb만 사용 가능?
	//32bit에선 몇개의 주소 공간이 사용 가능할까

}