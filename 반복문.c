#include <stdio.h>

//다음 소스 코드를 완성하여 정수 1, 2, 4, 8, 16, 32, 64, 128이 각 줄에 출력되게 만드세요.
void power()
{

}



int main()
{
    //for

    for (int i = 0, j = 0; i < 10; i++, j += 2)    // i는 1씩 증가, j는 2씩 증가
    {
        printf("i: %d, j: %d\n", i, j);
    }

 
    ///do


    unsigned char i = 1;
    while (i <= 64)
    {
        printf("%u\n", i);
        i <<= 1;
    }


    ///do-while

    int count;
    scanf("%d", &count);    // 값을 입력받음

    // 처음 한 번은 아래 코드가 실행됨
    int i = 0;
    do 
    {
        printf("Hello, world! %d\n", i);    // Hello, world!와 i의 값을 함께 출력
        i++;                                // i를 1씩 증가시킴
    } while (i < count);                    // i가 count보다 작을 때 반복



	///infinite loop
	for (;;)    // 초깃값, 조건식, 변화식을 모두 생략하면 무한 루프
	{
		printf("Hello, world!\n");
	}

	while (1)
	{

	}
	
	do
	{
		if(0)
		{
			break;
		}
		else if (0)
		{
			continue;
		}

	}
	while(1)
}
