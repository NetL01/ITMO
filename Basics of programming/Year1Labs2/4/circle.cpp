#include "circle.h"


Circle::Circle(const char *name, double radius, double x, double y)
        :
        class_name_(name),
        radius_(radius),
        centre_coordinats_({x, y})
{}

double Circle::square() {
    return PI * (radius_ * radius_);
}

double Circle::perimeter() {
    return 2 * PI * radius_;
}

double Circle::mass() const {
    return weight_;
}

CVector2D Circle::position() {
    return centre_coordinats_;
}

void Circle::draw() {
    std::cout << class_name_ << " {Centre: (" << centre_coordinats_.x << ", " << centre_coordinats_.y <<
              "), Mass: " << weight_ << ", Radius: " << radius_ << "}\n";
}

void Circle::initFromDialog() {
    std::cout << "Enter radius: \n";
    std::cin >> radius_;
    std::cout << "Enter coordinates of centre: \n";
    double x, y;
    std::cin >> x >> y;
    centre_coordinats_.x = x;
    centre_coordinats_.y = y;
    std::cout << "Enter weight: \n";
    std::cin >> weight_;
}

const char *Circle::classname() {
    return class_name_;
}

unsigned int Circle::size() {
    return sizeof(*this);
}

bool Circle::operator==(const IPhysObject &ob) const {
    return this->weight_ == ob.mass();
}

bool Circle::operator<(const IPhysObject &ob) const {
    return this->weight_ < ob.mass();
}

