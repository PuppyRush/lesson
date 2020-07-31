#include <stdio.h>

//https://dojang.io/pluginfile.php/715/mod_page/content/26/unit75-1.png

#define COUNT 10    // 10�� COUNT�� ����

#define PRINT_NUM(x) printf("%d\n", x)    // printf("%d\n", x)�� PRINT_NUM(x)�� ����

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main()
{
    printf("%d\n", COUNT);    // 10

#undef COUNT        // �տ��� ������ COUNT ����
#define COUNT 20    // 20�� COUNT�� ����

    printf("%d\n", COUNT);    // 20: #undef�� COUNT�� ������ �� 20�� COUNT�� ���������Ƿ� 20�� ��µ�

    PRINT_NUM(20);    // 20: printf("%d\n", 20)

    MAX(10, 20);

    return 0;
}