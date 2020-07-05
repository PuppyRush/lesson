
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	int x = 5;
	int y = 3;
	int z = 10;

	printf("%d\n", sizeof(int));

	printf("%0.2d %d\n", x / y * z, x*y / z);
	printf("%0.2f %f\n", x / y * z, x*y / z);
	printf("%0.2f %f\n", (double)x / y * z, (double)x*y / z);
	printf("%0.2f %f\n", x / (double)y * z, x*y / (double)z);

	return 0;

}

