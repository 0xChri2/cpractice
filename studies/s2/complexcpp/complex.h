//
// Created by Christoph Riedel on 18.04.23.
//

#ifndef COMPLEXCPP_COMPLEX_H
#define COMPLEXCPP_COMPLEX_H

class complex{
public:
    int _imag;
    int _real;
    complex();
    ~complex();
    complex *addComplex(complex *a, complex *b);
    complex *getComplex(double re, double im);
    complex t *mulComplex(complex *a, complex *b);
    complex t *subComplex(complex *a, complex *b);
    complex t *divComplex(complex *a, complex *b);
    void printComplex(complex *a);
    complex t *cleanComplex(complex *c);

};



#endif //COMPLEXCPP_COMPLEX_H
