#pragma once
#include <math.h>
#include "Interfaces.h"

const double PI = M_PI;

class Circle : public IGeoFig {
public:
    Circle() = default;
    Circle(const char* name, double radius, double x, double y);
    ~Circle() = default;

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
    const char* class_name_ = "Circle";
    double weight_;
    double radius_;
    CVector2D centre_coordinats_;
};