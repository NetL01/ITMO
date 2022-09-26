#include <stdio.h>

int main()
{
    int num, lastnum;
    scanf("%x", &num);
    printf("%o", num);
    printf("%x, so sdvigom - %x", num, num « 2);
    printf("%x, %x\n", num, ~num);
    scanf("%x", &lastnum);
    printf("%x", num | lastnum);
    return 0;
}