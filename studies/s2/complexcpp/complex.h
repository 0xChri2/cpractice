//
// Created by Christoph Riedel on 18.04.23.
//

#ifndef COMPLEXCPP_COMPLEX_H
#define COMPLEXCPP_COMPLEX_H

class complex{
public:
    int *_imag;
    int *_real;
    complex(double imag, double real);
    ~complex();
    complex *addComplex(complex *a, complex *b);
    complex *getComplex(double re, double im);
    complex *mulComplex(complex *a, complex *b);
    complex *subComplex(complex *a, complex *b);
    complex *divComplex(complex *a, complex *b);
    void printComplex(complex *a);
    complex *cleanComplex(complex *c);

};



#endif //COMPLEXCPP_COMPLEX_H
