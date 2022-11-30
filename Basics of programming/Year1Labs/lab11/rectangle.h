#ifndef RECTANGLE_H
#define REGTANGLE_H
struct data
{
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
};

float square (data rect);

float perimeter (data rect);

data create_struct (data rect);

#endif