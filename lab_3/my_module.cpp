#include "my_module.h"

Vector::Vector(){
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(double _x, double _y, double _z){
    x = _x;
    y = _y;
    z = _z;
}

Vector::Vector(string str){
    srand(time(nullptr));
    if (str == "rand"){
        x = rand() % 10 + rand() % 10 / 10.;
        y = rand() % 10 + rand() % 10 / 10.;
        z = rand() % 10 + rand() % 10 / 10.;
    }
    else{
        x = 0;
        y = 0;
        z = 0;
    }
}

double Vector::getX() const { return x; }
double Vector::getY() const { return y; }
double Vector::getZ() const { return z; }

Vector Vector::operator+(const Vector& v) const {
    return Vector(x + v.x, y + v.y, z + v.z);
}

double Vector::operator*(const Vector& v) const {
    return x * v.x + y * v.y + z * v.z;
}

void Vector::output(const string& name){
    cout << "Vector " << name << ": " << "(" << x << ", " << y << ", " << z << ")" << endl;
}

double Vector::length() const {
    return sqrt(x * x + y * y + z * z);
}

bool input(string &input, double *values) {
    stringstream ss(input);
    string token;
    for (int i = 0; i < 3; i++) {
        if (!getline(ss, token, ';')) {
            cout << "Invalid input. Please, try again" << endl;
            return false;
        }
        size_t pos;
        double value = stod(token, &pos);
        if (pos != token.size()) {
            cout << "Invalid input. Please, try again" << endl;
            return false;
        }
        values[i] = value;
    }
    return true;
}