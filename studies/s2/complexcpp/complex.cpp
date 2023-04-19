//
// Created by Christoph Riedel on 18.04.23.
//
#include "complex.h"
#include <iostream>

using namespace std;

complex::complex(double imag, double real){
    double *_imag = new double(imag);
    double *_real = new double(real);
}

complex::~complex(){
    delete _real;
    delete _imag;
}

complex* complex::addComplex(complex *a, complex *b){
    double real = *a->_real + *b->_real;
    double imag = *a->_imag + *b->_imag;
    return new complex(real, imag);
}

complex* complex::mulComplex(complex *a, complex *b){
    complex *result = new complex(0,0);
    *result->_real = *a->_real * *b->_real - *a->_imag * *b->_imag;
    *result->_imag = *a->_real * *b->_imag + *a->_imag * *b->_real;
    return result;
}

/*complex* complex::addComplex(complex *a, complex *b){
    double real = a->_real + b->_real;
    double imag = a->_imag + b->_imag;
    return new complex(imag, real);
}


complex* complex::mulComplex(complex *a, complex *b){

    double real = a->_real * b->_real - a->_imag * b->_imag;
    double imag = a->_real * b->_imag + a->_imag * b->_real;
    return new complex(imag, real);
}*/
/*
complex* complex::subComplex(complex *a, complex *b){
    double imag = a->_imag - b->_imag;
    double real = b->_real - b->_real;
    return new complex(imag,real);
}*/