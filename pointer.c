#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	
	int a = 10;
	printf("%p %d", &a, a); 

	//�������� ���
	int *ptr = &a;

	//������������ ���
	int** ptr2 = &ptr;

	//�� context�� ���꿡�� �޸𸮿��� �Ͼ�� ���� ����Ͽ� ������ ��µǴ��� �����غ���.
	printf("%p %d", &a, a);
	printf("%p %p %d", &ptr, ptr, *ptr);
	printf("%p %p %p %d", &ptr2, ptr2, *ptr2, **ptr2);

	//32bit������ �� ���� �ִ� �뷮�� 4gb�ϱ�?
	//32bit���� ��� �ּ� ������ �̷������� ��� �����ұ�?
}