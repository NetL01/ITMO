#include "rectangle.h"


Rectangle::Rectangle(const char *name, double weihgt, double x_a, double x_b, double x_c, double x_d,
                     double y_a, double y_b, double y_c, double y_d)
        : class_name_(name),
          weight_(weihgt),
          a_({x_a, y_a}),
          b_({x_b, y_b}),
          c_({x_c, y_c}),
          d_({x_d, y_d})
{
    width_ = sqrt(pow(x_a - x_b, 2) + pow(y_a - y_b, 2));
    length_ = sqrt(pow(x_b - x_c, 2) + pow(y_b - y_c, 2));
}

double Rectangle::square() {
    return length_ * width_;
}

double Rectangle::perimeter() {
    return 2 * (width_ + length_);
}

double Rectangle::mass() const {
    return weight_;
}

CVector2D Rectangle::position() {
    return a_;
}

void Rectangle::draw() {
    std::cout << class_name_ << " {A: (" << a_.x << ", " << a_.y <<
                "), " << " B: (" << b_.x << ", " << b_.y <<
                "), " << " C: (" << c_.x << ", " << c_.y <<
                "), " << " D: (" << d_.x << ", " << d_.y <<
                "), weight: " << weight_ << "}\n";
}

void Rectangle::initFromDialog() {
    double x, y;
    std::cout << "Enter x_A, y_A: \n";
    std::cin >> x >> y;
    a_.x = x, a_.y = y;
    std::cout << "Enter x_B, y_B: \n";
    std::cin >> x >> y;
    b_.x = x, b_.y = y;
    std::cout << "Enter x_C, y_C: \n";
    std::cin >> x >> y;
    c_.x = x, c_.y = y;
    std::cout << "Enter x_D, y_D: \n";
    std::cin >> x >> y;
    d_.x = x, d_.y = y;
    std::cout << "Enter weight: \n";
    std::cin >> weight_;
}

const char *Rectangle::classname() {
    return class_name_;
}

unsigned int Rectangle::size() {
    return sizeof(*this);
}

bool Rectangle::operator==(const IPhysObject &ob) const {
    return this->weight_ == ob.mass();
}

bool Rectangle::operator<(const IPhysObject &ob) const {
    return this->weight_ < ob.mass();
}