#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//�μ��� ������ Data�� ũ�Ⱑ �ſ� ū ��쿡 �μ����� ȿ���� ���� �� �ִ� , ����Ʈ
//�迭 ÷�ڿ����� ���������� Pointer �����̴�.
//void ptr?
//�Լ�������

int main()
{
	
	//������ ������
	int a = 10;
	printf("%x", &a); 

	int *ptr = &a;
	//ptr = ?
	//*ptr = ?

	int *ptr2 = NULL;
	//ptr2 = ?
	//*ptr2 = ?

	int** ptr3 = NULL; //**�� ���?
	
	//32bit���� �� 4gb�� ��� ����?
	//32bit���� ��� �ּ� ������ ��� �����ұ�

}