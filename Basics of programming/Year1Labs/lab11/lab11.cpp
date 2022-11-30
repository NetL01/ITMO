#include "rectangle.h"
#include <math.h>
#include <stdio.h>

float square (data rect)
{
    float squ = (sqrt(pow(rect.x2-rect.x1,2)+pow(rect.y2-rect.y1,2))*sqrt(pow(rect.x3-rect.x2,2)+pow(rect.y3-rect.y2,2)));
    return squ;
}

float perimeter (data rect)
{
    float per = 2*sqrt(pow(rect.x2-rect.x1,2)+pow(rect.y2-rect.y1,2))+2*sqrt(pow(rect.x3-rect.x2,2)+pow(rect.y3-rect.y2,2));
    return per;
}

data create_struct (data rect)
{
    printf("Write the coordinates of the corner points\n");
    scanf("%f %f %f %f %f %f", &rect.x1, &rect.y1, &rect.x2, &rect.y2, &rect.x3, &rect.y3 );
    return rect;
}

int main ()
{
    data exz;
    float sq, per;
    exz = create_struct (exz);
    sq = square (exz);
    per = perimeter (exz);
    printf("Square: %f, Perimeter: %f", sq, per);
    return 0;
}