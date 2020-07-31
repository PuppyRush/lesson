#include <stdio.h>

#include <stdio.h>


void hello()     // 반환값과 매개변수가 없음
{
    printf("Hello, world!\n");
}


int ret_no_param()     // 반환값과 매개변수가 없음
{
    return 10;
}


int ret_param(int a,int b)     // 반환값과 매개변수가 없음
{
    return a + b;
}


int main()
{
    void (*fp)();   // 반환값과 매개변수가 없는 함수 포인터 fp 선언

    fp = hello;     // hello 함수의 메모리 주소를 함수 포인터 fp에 저장
    fp();           // Hello, world!: 함수 포인터로 hello 함수 호출

    //////

    int (*ret_int)();
    ret_int = ret_no_param;
    int i = ret_int;
    

    /////

    int (*ret_int_param_ptr)(int,int);
    ret_int_param_ptr = ret_param;
    printf("%d",ret_int_param_ptr(5, 10));

    return 0;
}


//int main()
//{
//    int funcNumber;    // 함수 번호
//    int num1, num2;
//    int (*fp[4])(int, int);    // int형 반환값, int형 매개변수 두 개가 있는 함수 포인터 배열 선언
//
//    fp[0] = add;    // 첫 번째 요소에 덧셈 함수의 메모리 주소 저장
//    fp[1] = sub;    // 두 번째 요소에 뺄셈 함수의 메모리 주소 저장
//    fp[2] = mul;    // 세 번째 요소에 곱셈 함수의 메모리 주소 저장
//    fp[3] = div;    // 네 번째 요소에 나눗셈 함수의 메모리 주소 저장
//
//    printf("함수 번호와 계산할 값을 입력하세요: ");
//    scanf("%d %d %d", &funcNumber, &num1, &num2);    // 함수 번호와 계산할 값을 입력받음
//
//    printf("%d\n", fp[funcNumber](num1, num2));    // 함수 포인터 배열을 인덱스로 접근하여 함수 호출
//
//    return 0;
//}