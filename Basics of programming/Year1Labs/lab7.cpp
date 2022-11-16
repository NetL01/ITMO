#include <stdio.h>
#include <math.h>

enum days {
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
};
struct Point{
    int x;
    int y;
    int r;
};
struct Circle{
    Point point_x;
    Point point_y;
    Point radius;
};
double get_perimeter(Circle obj){
    double perimeter = 2 * M_PI * obj.radius.r;
    return perimeter;
}

struct Modem{
    union{
        unsigned int dsl:1, ppp:1, link:1;
    };
    int flag;
};


int main()
{
    days currentDay = monday;
    /* std::cout << "Day: " << currentDay << std::endl; */
    printf("Day: %d", currentDay);
    printf("\n");
    Circle mycircle;
    mycircle.point_x.x = 10;
    mycircle.point_y.y = 10;
    mycircle.radius.r = 5;
    /* std::cout << get_perimeter(mycircle); */
    printf("Perimeter: %f \n", get_perimeter(mycircle));
    int hex;
    scanf("%hx", &hex);
    Modem modem;
    modem.flag = hex;
    if (modem.flag && modem.dsl){
        printf("\nDSL on");
    }
    else {
        printf("\nDSL off");
    }
    if (modem.flag>>1 && modem.ppp) {
        printf("\nPPP on");
    }
    else {
        printf("\nPPP off");
    }
    if (modem.flag>>2 && modem.link) {
        printf("\nLINK on");
    }
    else {
        printf("\nLINK off");
    }
    return 0;
}