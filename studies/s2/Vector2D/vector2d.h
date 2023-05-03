#ifndef VECTOR2D_VECTOR2D_H
#define VECTOR2D_VECTOR2D_H

class vector2d{
private:


public:
    double _x, _y;
    vector2d(double _x = 0.00, double _y = 0.00);
    ~vector2d();
    double operator*(const vector2d &y) const;
    vector2d operator+(const vector2d &y) const;
    friend std::istream& operator>>(std::istream& is, vector2d& v);
    friend std::ostream& operator<<(std::ostream& os, vector2d& v);
    void turn(double alpha);
};

#endif //VECTOR2D_VECTOR2D_H
