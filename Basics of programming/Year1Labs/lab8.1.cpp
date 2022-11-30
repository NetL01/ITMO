#include <string.h>
#include <stdio.h>
#include <string>

int main() {
    char first_string[50], second_string[50];
    /* concatenate */
    printf("First string\n");
    scanf("%s", &first_string);
    printf("Second string\n");
    scanf("%s", &second_string);

    strcat(first_string, second_string);
    printf("Concatenate: %s\n", first_string);
    /* comparison */
    printf("First string\n");
    scanf("%s", &first_string);
    printf("Second string\n");
    scanf("%s", &second_string);
    int n;
    printf("enter n: \n");
    scanf("%d", &n);
    if (strncmp(first_string, second_string, n) == 0){
        printf("n strings are identify\n");
    }
    else {
        printf("n strings are not identify\n");
    }

    /* len */
    printf("First string for len\n");
    scanf("%s", &first_string);
    printf("%zu\n", strlen(first_string));

    /* f_occurance */
    char ne;
    printf("First string for f_occurance\n");
    scanf("%s", &first_string);
    printf("Enter a simb\n");
    scanf("%s", &ne);
    char *asbl = strchr(first_string, ne);
    printf("%d\n", asbl - first_string + 1);

    /* complex_find */
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

    return 0;
}