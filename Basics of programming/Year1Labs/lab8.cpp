/* 1, 4, 7, 8, lab11 */

#include <string.h>
#include <stdio.h>


int concatenate(){
    printf("concatenate\n");
    char one[10];
    char two[10];
    printf("Enter two strings: \n");
    fgets(one, 10, stdin);
    fflush(stdin);
    fgets(two, 10, stdin);
    /* printf("%s, %s", one, two); */
    strcat(one,two);
    printf("\nConcatenated String: %s\n", one);
    return 0;
}
int comparison(){
    printf("comparison\n");
    char one[10];
    char two[10];
    printf("Enter two strings: \n");
    fgets(one, 10, stdin);
    fflush(stdin);
    fgets(two, 10, stdin);
    int n;
    printf("enter n: \n");
    scanf("%d", &n);
    if (strncmp(one, two, n) == 0){
        printf("n strings are identify");
    }
    else {
        printf("n strings are not identify");
    }
    return 0;
}

int len(){
    printf("len()\n");
    char one[10];
    printf("Enter string: \n");
    fgets(one, 10, stdin);
    printf("%zu", strlen(one)-1);
    return 0;
}

int f_occurrence() {
    printf("f_occurrence()\n");
    printf("Enter string: \n");
    char one[100];
    fgets(one, 100, stdin);
    fflush(stdin);
    printf("Enter finding char: \n");
    int f_chr;
    scanf("%d", &f_chr);
    char* pos = strchr(one, f_chr);
    printf("Finding char on pos: %d", (pos - one + 1));
    return 0;
}

int complex_find() {
    printf("complex_find() \n");
    printf("Enter two strings: \n");
    char one[100];
    char two[100];

    scanf("%s", &one);
    scanf("%s", &two);
    int count = 0;
    int maxcount = 0;
    for (int i = 0; i < strlen(two); i++){
       if (strchr(one, two[i])) {
           count++;
           if (count > maxcount) {
               maxcount = count;
           }
       } else {
           count = 0;
       }
    }


    printf("Len of maxfinds: %d", maxcount);
}

int main(){
    concatenate();
    comparison();
    len();
    f_occurrence();
    complex_find();
    return 0;
}