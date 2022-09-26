#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    fflush(stdin);

    char s[15];
    scanf("%14[a-zA-Z !]", s);
    printf("%15s - строка, %d - целое число.", s, num);
    return 0;
}