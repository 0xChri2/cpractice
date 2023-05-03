#include <iostream>
#include "vector2d.h"

vector2d::vector2d(double x, double y) : _x(x), _y(y){}

vector2d::~vector2d() {}

vector2d vector2d::operator+(const vector2d& y) const {
    vector2d result;
    result._x = _x + y._x;
    result._y = _y + y._y;
    return result;
}

double vector2d::operator*(const vector2d &y) const {
    double result = (_x * y._x)+(_y * y._y);
    return result;
}

std::istream& operator>>(std::istream& is, vector2d& v) {
    is >> v._x >> v._y;
    return is;
}

std::ostream& operator<<(std::ostream& os, vector2d& v){
    os << "(" << v._x << ", " << v._y << ")";
    return os;
}

void vector2d::turn(double alpha){
    double rad = alpha * M_PI / 180.00;
    double x_neu = _x * cos(rad) - _y * sin(rad);
    double y_neu = _x * sin(rad) + _y * cos(rad);
    _x = x_neu;
    _y = y_neu;
}


