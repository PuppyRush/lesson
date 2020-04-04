#include <stdio.h>

#pragma pack(2)

typedef enum Month
{
	Jaunary,
	Februray,
	March,
	April,
	May,
	June,
	July,
	Agust
}Month;

enum Major
{
	ComputerScience,
	Math,
	Philosophy,
	History,
	Economy
};

typedef struct 
{
	int age;
	int gredee;
	char name[13];
	Month month;

}student;

int main()
{
	//void*

	//구조체 선언
	
	//구조체 만들기

	//구조체 초기화

	//구조체와 활용(nested)

	//구조체와 포인터

	//구조체와 크기

	//enum

	student s;
	printf("%d\n", sizeof(s));

	student man[10];
	student *ptr = man;
	sizeof(*ptr);
	
	for (int i = 0; i < 10; i++)
	{
		printf("%p\n", &man[i]);
		(*ptr).age = (i + 1) * 10;
		printf("%p %d\n", (ptr + i), ptr->age);
	}

	//enum

	

}