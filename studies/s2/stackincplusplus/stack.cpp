//
// Created by Chris on 28/03/2023.
//
#include <iostream>
#include "stack.h"
#include <cstdlib>
#include <cstdio>

template<typename T>
mystack_t<T>::mystack_t(){
    _data = new T[10];
    _size = 0;
    _capacity = 10;
    _error = 0;
}
template<typename T>
mystack_t<T>::~mystack_t(){
    delete[] _data;
}
template<typename T>
char mystack_t<T>::isEmpty(){
    return _size == 0;
}
template<typename T>
void mystack_t<T>::push(T value){
    if(_size == _capacity){
        _error = 1;
        return;
    }
    _data[_size] = value;
    _size++;
}

template<typename T>
T mystack_t<T>::pop(){
    if (_size == 0) {
        _error = 1;
        return T();
    }
    _size--;
    return _data[_size];
}

template<typename T>
char mystack_t<T>::getError(){
    return _error;
}
