#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    num > -77 && num < 1 ? printf("True") : printf("False");
    int seq;
    scanf("%x", seq);
    printf ("%d", (seq » 18) % 2);
    return 0
}