#include <iostream>
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

struct Circle{
    int posX;
    int posY;
    int radius;


    int perimeter(){
        return 2 * M_PI * radius;
    }
    int square(){
        return M_PI * (radius*radius);
    }
};
int main()
{
    days currentDay = monday;
    std::cout << "Day: " << currentDay;

    Circle circle;
    circle.radius = 5;
    circle.posX = 10;
    circle.posY = 10;
    circle.perimeter();
    circle.square();
    return 0;
}