#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{

	//문자열 초기화

	//1
	char* str1 = "Hello World";

	//2
	char str2[100];
	memset(str2, 0, 100);
	strcpy_s(str2, 100, "Hello World!!!");

	//str2 = str1;
	str1 = str2;

	char ary_ptr[3][10] = { "abc","eft","gasd" };
	char* ary_ptr2[3] = { "absdadc","eftsadds","gasdsadsaasd" };


	//3
	char str3[100];
	scanf("%s", str3);		//&?

	//문자열 저장 및 순회
	char* string[10] = { "","", "" };

	//argc argv
}