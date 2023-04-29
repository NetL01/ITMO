#include "Classes.h"


Square::Square(double x, double y, double l, double a) {
    this->coordinate_x = x;
    this->coordinate_y = y;
    this->length = l;
    this->angle = a;
}

void Square::Set_X(double x) {
    this->coordinate_x = x;
}

void Square::Set_Y(double y) {
    this->coordinate_y = y;
}

void Square::Set_Lenght(double l) {
    this->length = l;
}

void Square::Set_Angle(double a) {
    this->angle = a;
}

double Square::Get_X() {
    return this->coordinate_x;
}

double Square::Get_Y() {
    return this->coordinate_y;
}

double Square::Get_Lenght() {
    return this->length;
}

double Square::Get_Angle() {
    return this->angle;
}

/* a = b * c;
a+=b;
 */
Square operator*(Square &obj, double x) {
    return Square(obj.coordinate_x, obj.coordinate_y, obj.length * x, obj.angle);
}
Square operator+(Square &obj, std::pair<double, double> vector) {
    return Square(obj.coordinate_x + vector.first, obj.coordinate_y + vector.second, obj.length, obj.angle);
}

bool Square::operator==(const Square &right) {
    return (this->length * this->length == right.length * right.length);
}

bool Square::operator!=(const Square &right) {
    return !(*this == right);
}

bool Square::operator<(const Square &right) {
    return (this->length * this->length < right.length * right.length);
}

bool Square::operator>(const Square &right) {
    return (this->length * this->length > right.length * right.length);
}


int Array::operator[](size_t index) {
    if (index < 100) return this->arr[index];
    else std::cerr << "Out of array\n";
}

void Array::Set(size_t index, int value) {
    this->arr[index] = value;
    this->size++;
}

void Array::Remove(size_t index) {
    this->arr[index] = 0;
    this->size--;
}

Array Array::operator+(const Array &right) {
    int t = this->size;
    for (int i = this->size; i < std::min(100, right.size + t); i++) {
        this->arr[i] = right.arr[i - t];
        this->size++;
    }
    return *this;
}

bool Array::operator==(const Array &right) {
    return (this->size == right.size);
}

bool Array::operator!=(const Array &right) {
    return (this->size == right.size);
}

bool Array::operator>(const Array &right) {
    return (this->size > right.size);
}

bool Array::operator<(const Array &right) {
    return (this->size < right.size);
}

void Array::Print() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->arr[i] << '\n';
    }
}

int Array::Get_Size() {
    return this->Get_Size();
}