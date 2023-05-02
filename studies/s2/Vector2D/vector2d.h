#ifndef VECTOR2D_VECTOR2D_H
#define VECTOR2D_VECTOR2D_H

class vector2d{
private:
    int x1, x2,y1,y2;

public:
    vector2d();
    ~vector2d();
    vector2d operator*();
    vector2d operator+();
    vector2d operator-();
    vector2d operator/();

};

#endif //VECTOR2D_VECTOR2D_H
