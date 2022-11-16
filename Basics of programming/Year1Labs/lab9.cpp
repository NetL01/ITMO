#include <stdio.h>
#include <string.h>


int bank_sys() {
    printf("\nWelcome to bank.");
    int total_min, abonem_price, price_over_min;
    printf("Enter total minutes: \n");
    scanf("%d", &total_min);
    printf("Enter ab. price: \n");
    scanf("%d", &abonem_price);
    printf("Enter price over you abonement minutes: \n");
    scanf("%d", &price_over_min);
    int result;
    unsigned int count_minutes_over_price = total_min - 499;
    result = abonem_price + count_minutes_over_price*price_over_min;
    printf("Your total month price: %d", result);
    return 0;
}

int main(){
    char mas[255];
    int len, count_nums,count_dig, count_nodig;
    count_nums = 0;
    count_dig = 0;
    count_nodig = 0;
    printf("Enter string: \n");
    gets(mas);
    /* for nums */
    for(int i=0; i<strlen(mas); i++){
        if (mas[i]>='0' && mas[i]<='9') {
            count_nums++;
        }
    }
    /* for letters */
    for(int i=0; i<strlen(mas); i++){
        if (mas[i]>='A' && mas[i]<='Z') {
            count_dig++;
        }
        if (mas[i]>='a' && mas[i] <= 'z') {
            count_nodig++;
        }
    }
    printf("The are %d nums in this string.\n", count_nums);
    printf("Large letters - %d,small letters - %d .", count_dig, count_nodig);
    bank_sys();
    return 0;
}