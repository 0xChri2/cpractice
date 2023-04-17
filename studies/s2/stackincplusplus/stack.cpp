//
// Created by Chris on 28/03/2023.
//
#include "stack.h"
#include <cstdlib>
#include <cstdio>

mystack_t::mystack_t(){
    _data = new float[10];
    _size = 0;
    _capacity = 10;
    _error = 0;
}

mystack_t::~mystack_t(){
    delete[] _data;
}

char mystack_t::isEmpty(){
    return _size == 0;
}

void mystack_t::push(float value){
    for(int i = 0;i<= _size;i++){
        _data[i] = 1;
    }
}

float mystack_t::pop(){
    return _data[_size];
}

char mystack_t::getError(){
    return _error;
}
