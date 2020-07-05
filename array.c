#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{

	char str[1000];
	memset(str, 0, 1000);

	char c;
	int idx = 0;
	while ( (c =getchar()) != '\n')
	{
		str[idx++] = c;
	}
	
	str[idx] = idx++;

	printf("%s", str);

	
}