#pragma once
#include <iostream>


class CVector2D {
public:
    double x, y;
};


class IPhysObject {
public:
    virtual double mass() const = 0;
    virtual CVector2D position() = 0;
    virtual bool operator==(const IPhysObject &ob) const = 0;
    virtual bool operator<(const IPhysObject &ob) const = 0;
};


class IPrintable {
public:
    virtual void draw() = 0;
};


class IDialogInitiable {
public:
    virtual void initFromDialog() = 0;
};


class BaseCObject {
public:
    virtual const char *classname() = 0;
    virtual unsigned int size() = 0;
};


class IGeoFig : public CVector2D, public IPhysObject, public IPrintable,
                public IDialogInitiable, public BaseCObject
{
public:
    virtual double square() = 0;
    virtual double perimeter() = 0;
};