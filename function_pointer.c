#include <stdio.h>

#include <stdio.h>


void hello()     // ��ȯ���� �Ű������� ����
{
    printf("Hello, world!\n");
}


int ret_no_param()     // ��ȯ���� �Ű������� ����
{
    return 10;
}


int ret_param(int a,int b)     // ��ȯ���� �Ű������� ����
{
    return a + b;
}


int main()
{
    void (*fp)();   // ��ȯ���� �Ű������� ���� �Լ� ������ fp ����

    fp = hello;     // hello �Լ��� �޸� �ּҸ� �Լ� ������ fp�� ����
    fp();           // Hello, world!: �Լ� �����ͷ� hello �Լ� ȣ��

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
//    int funcNumber;    // �Լ� ��ȣ
//    int num1, num2;
//    int (*fp[4])(int, int);    // int�� ��ȯ��, int�� �Ű����� �� ���� �ִ� �Լ� ������ �迭 ����
//
//    fp[0] = add;    // ù ��° ��ҿ� ���� �Լ��� �޸� �ּ� ����
//    fp[1] = sub;    // �� ��° ��ҿ� ���� �Լ��� �޸� �ּ� ����
//    fp[2] = mul;    // �� ��° ��ҿ� ���� �Լ��� �޸� �ּ� ����
//    fp[3] = div;    // �� ��° ��ҿ� ������ �Լ��� �޸� �ּ� ����
//
//    printf("�Լ� ��ȣ�� ����� ���� �Է��ϼ���: ");
//    scanf("%d %d %d", &funcNumber, &num1, &num2);    // �Լ� ��ȣ�� ����� ���� �Է¹���
//
//    printf("%d\n", fp[funcNumber](num1, num2));    // �Լ� ������ �迭�� �ε����� �����Ͽ� �Լ� ȣ��
//
//    return 0;
//}