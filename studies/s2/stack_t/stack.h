//
// Created by Chris on 28/03/2023.
//

#ifndef STACK_T_STACK_H
#define STACK_T_STACK_H

typedef struct {
    float *data;
    int size;
    int capacity;
    int error;
}stack_t;

stack_t *createStack();
char isEmpty(stack_t *s);
void push(stack_t *s, float value);
float top(stack_t *s);
void pop(stack_t *s);
char getError(stack_t *s);
void destroyStack(stack_t *s);

#endif //STACK_T_STACK_H
