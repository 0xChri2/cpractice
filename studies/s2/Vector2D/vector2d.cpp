#include <iostream>
#include "vector2d.h"

vector2d::vector2d(int x, int y) : _x(x), _y(y){}

vector2d::~vector2d() {}

vector2d vector2d::operator+(const vector2d& y) const {
    vector2d result;
    result._x = _x + y._x;
    result._y = _y + y._y;
    return result;
}

int vector2d::operator*(const vector2d &y) const {
    int result = (_x * y._x)+(_y * y._y);
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


