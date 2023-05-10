//
// Created by Chris on 28/03/2023.
//

#ifndef STACK_H
#define STACK_H

template<typename T>
class mystack_t{
    public:
        mystack_t();
        ~mystack_t();
        char isEmpty();
        void push(T value);
        T top();
        T pop();
        char getError();
    T *_data;
    int _capacity;
    int _error;
    int _size;
};

#endif //STACK_H