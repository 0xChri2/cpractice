#ifndef STACKCOM_H
#define STACKCOM_H

#include <cstdlib>
#include <cstdio>

template<typename T>
class mystack_t {
public:
    mystack_t() {
        _data = new T[10];
        _size = 0;
        _capacity = 10;
        _error = 0;
    }

    ~mystack_t() {
        delete[] _data;
    }

    bool isEmpty() {
        return _size == 0;
    }

    void push(T value) {
        if(_size == _capacity) {
            _error = 1;
            return;
        }
        _data[_size] = value;
        _size++;
    }

    T top() {
        return _data[_size-1];
    }

    T pop() {
        _size--;
        return _data[_size];
    }

    char getError() {
        return _error;
    }

private:
    T *_data;
    int _capacity;
    int _error;
    int _size;
};

#endif //STACK_COMBINED_H

