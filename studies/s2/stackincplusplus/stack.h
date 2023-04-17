//
// Created by Chris on 28/03/2023.
//

#ifndef STACK_T_STACK_H
#define STACK_T_STACK_H
class mystack_t{
    public:
        mystack_t();
        ~mystack_t();
        char isEmpty();
        void push(float value);
        float top();
        float pop();
        char getError();
    float *_data;
    int _capacity;
    int _error;
    int _size;
};



#endif //STACK_T_STACK_H
