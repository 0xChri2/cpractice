#ifndef VECTOR2D_VECTOR2D_H
#define VECTOR2D_VECTOR2D_H

class vector2d{
private:


public:
    int _x, _y;
    vector2d(int _x = 0, int _y = 0);
    ~vector2d();
    int operator*(const vector2d &y) const;
    vector2d operator+(const vector2d &y) const;
    friend std::istream& operator>>(std::istream& is, vector2d& v);
    friend std::ostream& operator<<(std::ostream& os, vector2d& v);
    //vector2d operator/();

};

#endif //VECTOR2D_VECTOR2D_H
