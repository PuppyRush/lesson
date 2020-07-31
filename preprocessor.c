#include <stdio.h>

//https://dojang.io/pluginfile.php/715/mod_page/content/26/unit75-1.png

#define COUNT 10    // 10을 COUNT로 정의

#define PRINT_NUM(x) printf("%d\n", x)    // printf("%d\n", x)를 PRINT_NUM(x)로 정의

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main()
{
    printf("%d\n", COUNT);    // 10

#undef COUNT        // 앞에서 정의한 COUNT 해제
#define COUNT 20    // 20을 COUNT로 정의

    printf("%d\n", COUNT);    // 20: #undef로 COUNT를 해제한 뒤 20을 COUNT로 정의했으므로 20이 출력됨

    PRINT_NUM(20);    // 20: printf("%d\n", 20)

    MAX(10, 20);

    return 0;
}