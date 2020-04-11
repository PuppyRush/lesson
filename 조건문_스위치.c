#define _CRT_SECURE_NO_WARNINGS    // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>

int main()
{
    const int A = 10;
    char c1;

    scanf("%c", &c1);     // 값을 입력받음

    switch (c1)  // c1의 값에 따라 분기
    {
    case 3:
        printf("%c입니다.\n", 3);
        break;
    case 'a':    // 문자 a일 때
        printf("a입니다.\n");
        break;
    case A:    // 문자 b일 때
        printf("b입니다.\n");
        break;
    default:    // 아무 case에도 해당되지 않을 때
        printf("default\n");
        break;
    }

    return 0;
}