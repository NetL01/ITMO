#include <stdio.h>
#include <malloc.h>

int main() {
    char array[4];

    for (char *i = array; i < (array + 4); i++){
        scanf("%s", i);
    }
    for (char *i = array; i < (array + 4); i++){
        printf("%c ", *i);
    }
    printf("\n");
    char * arr;
    arr = (char*)malloc (4 * sizeof (char));
    char s;
    for (char *s = arr; s < (arr + 4); s++) {
        scanf("%s", (s));
    }

    for (char *s = arr; s < (arr + 4); s++) {
        printf("%c\n", *s);
    }
    free(arr);

}