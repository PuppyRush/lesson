#include <stdio.h>

#pragma pack(1)

typedef struct 
{
	int age;
	int gredee;
	//char name[13];
	//major

}student;

enum Month
{
	Jaunary,
	Februray,
	March,
	April,
	May,
	June,
	July,
	Agust
};

enum Major
{
	ComputerScience,
	Math,
	Philosophy,
	History,
	Economy
};

int main()
{

	//����ü ����
	
	//����ü �����

	//����ü �ʱ�ȭ

	//����ü�� Ȱ��(nested)

	//����ü�� ������

	//����ü�� ũ��

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