#ifndef LAB_3_MY_MODULE_H
#define LAB_3_MY_MODULE_H

#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

class Vector {
    double x, y, z;

public:
    Vector();

    Vector(double _x, double _y, double _z);

    Vector(string str);

    double getX() const;
    double getY() const;
    double getZ() const;

    double length() const;

    Vector operator+(const Vector& v) const;

    double operator*(const Vector& v) const;

    void output(const string& name);

};

bool input(string &input, double *values);

#endif //LAB_3_MY_MODULE_H
