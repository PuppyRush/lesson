
#include <stdio.h>

//���� �ҽ� �ڵ带 �ϼ��Ͽ� ���� 1, 2, 4, 8, 16, 32, 64, 128�� �� �ٿ� ��µǰ� ���弼��.
int main()
{


    //for

    for (int i = 0, j = 0; i < 10; i++, j += 2)    // i�� 1�� ����, j�� 2�� ����
    {
        printf("i: %d, j: %d\n", i, j);
    }

    for (;;)    // �ʱ갪, ���ǽ�, ��ȭ���� ��� �����ϸ� ���� ����
    {
        printf("Hello, world!\n");
    }


    //do

//
//    unsigned char i = 1;
//    while (_______)
//    {
//        printf("%u\n", i);
//        i <<= 1;
//    }
//    return 0;


    //do-while

    //int count;

    //scanf("%d", &count);    // ���� �Է¹���

    //int i = 0;
    //do // ó�� �� ���� �Ʒ� �ڵ尡 �����
    //{
    //    printf("Hello, world! %d\n", i);    // Hello, world!�� i�� ���� �Բ� ���
    //    i++;                                // i�� 1�� ������Ŵ
    //} while (i < count);                    // i�� count���� ���� �� �ݺ�
}
