#include <stdio.h>
#include <time.h>

int main() {
    time_t t= time(NULL);
    tm* p = localtime(&t);
    int count = 1;
    FILE*output = fopen("C:\\Users\\razuv\\CLionProjects\\ITMO\\Basics of programming\\Year1Labs\\file.txt", "w");
    int mon = p->tm_mon + 1;
    int day = p->tm_mday;
    int year = p->tm_year+1900;
    bool flag_add = false;
    for (int i = 0; i < 9 ; i++){
        if (flag_add){
            break;
        }
        if (day+i<=30){
            fprintf(output, "%04d/%02d/%02d \n",p->tm_year+1900,p->tm_mon+1,p->tm_mday+i);
        }
        else {
            for (int j = i; j < 9 ; j++){
                printf("%d", j);
                fprintf(output, "%04d/%02d/%02d \n",p->tm_year+1900,p->tm_mon+2, count);
                count = count + 1;
            }
            flag_add = true;
        }

    }
    fclose(output);
    return 0;
}