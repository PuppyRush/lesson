#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{

	//���ڿ� �ʱ�ȭ
	
	//1
	char *str1 = "Hello World";

	//2
	char str2[100];
	memset(str2, 0, 100);
	strcpy_s(str2, 100, "Hello World!!!");

	//3
	char str3[100];
	scanf("%s", str3);		//&?
	
	//���ڿ� ���� �� ��ȸ

	//argc argv
}