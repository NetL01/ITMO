#pragma once
#include <iostream>

class Square {
public:
    Square(double x, double y, double l, double a);

    void Set_X(double x);
    void Set_Y(double y);
    void Set_Lenght(double l);
    void Set_Angle(double a);

    double Get_X();
    double Get_Y();
    double Get_Lenght();
    double Get_Angle();

    friend Square operator*(Square &obj, double x);
    friend Square operator+(Square &obj, std::pair<double, double> vector);
    bool operator==(const Square &right);
    bool operator!=(const Square &right);
    bool operator<(const Square &right);
    bool operator>(const Square &right);

private:
    double coordinate_x;
    double coordinate_y;
    double length;
    double angle;
};


class Array {
public:
    Array() = default;
    int operator[](size_t index);
    void Set(size_t index, int value);
    void Remove(size_t index);
    void Print();
    int Get_Size();

    Array operator+(const Array &right);
    bool operator==(const Array &right);
    bool operator!=(const Array &right);
    bool operator>(const Array &right);
    bool operator<(const Array &right);
private:
    int arr[100] = {0};
    int size = 0;
};

