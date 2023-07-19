#include <iostream>
#include <cmath>
using namespace std;
class vector2d{
private:
    int _x;
    int _y;
public:
    vector2d(int x = 0, int y = 0) : _x(x), _y(y){};
    ~vector2d(){};
    vector2d operator+(vector2d b){
        vector2d result(0,0);
        result._x = _x + b._x;
        result._y = _y + b._y;
        return result;
    }
    vector2d operator-(vector2d b){
        vector2d result;
        result._x = _x - b._x;
        result._y = _y - b._y;
        return result;
    }
    int operator*(vector2d b){
        return (_x * b._x + _y * b._y);
    }
    void drehe(double alpha) {
        double tempX = cos(alpha) * _x - sin(alpha) * _y;
        double tempY = sin(alpha) * _x + cos(alpha) * _y;
        _x = tempX;
        _y = tempY;
    }
    friend ostream& operator<<(ostream& os,vector2d b){
        os << " ( " << b._x << " " << " " << b._y << " ) \n";
        return os;
    }
};

int main() {
    vector2d v1(2,2);
    vector2d v2(5,9);
    vector2d v3 = v1 + v2;
    cout << v3 << endl;
    v3 = v1 * v2;
    cout << v3 << endl;
    v3 = v1 - v2;
    cout << v3 << endl;
    v3.drehe(90);
    v3.drehe(90);
    v3.drehe(90);
    cout << v3 << endl;
}
