#pragma once
#include <math.h>
#include "Interfaces.h"


class Rectangle : public IGeoFig {
public:
    Rectangle() = default;
    Rectangle(const char *name, double weihgt, double x_a, double x_b, double x_c, double x_d,
              double y_a, double y_b, double y_c, double y_d);
    ~Rectangle() = default;

    double square() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() override;
    void draw() override;
    void initFromDialog() override;
    const char *classname() override;
    unsigned int size() override;
    bool operator==(const IPhysObject &ob) const override;
    bool operator<(const IPhysObject &ob) const override;

private:
    const char* class_name_ = "Rectangle";
    CVector2D a_;
    CVector2D b_;
    CVector2D c_;
    CVector2D d_;
    double length_;
    double width_;
    double weight_;
};