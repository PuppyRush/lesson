#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    const int A = 10;
    char c1;

    scanf("%c", &c1);     // ���� �Է¹���

    switch (c1)  // c1�� ���� ���� �б�
    {
    case 3:
        printf("%c�Դϴ�.\n", 3);
        break;
    case 'a':    // ���� a�� ��
        printf("a�Դϴ�.\n");
        break;
    case A:    // ���� b�� ��
        printf("b�Դϴ�.\n");
        break;
    default:    // �ƹ� case���� �ش���� ���� ��
        printf("default\n");
        break;
    }

    return 0;
}