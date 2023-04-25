#ifndef CARSALE_SALE_H
#define CARSALE_SALE_H
#include <iostream>
using namespace std;

class sale{
    private:
        string _car;
        int _date;
        int _sales;
    public:
        sale(int date,string car,  int sales);
        ~sale();
        string getcar();
        int getdate();
        int getsales();

};

#endif //CARSALE_SALE_H
