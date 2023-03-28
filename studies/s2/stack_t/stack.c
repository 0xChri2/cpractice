//
// Created by Chris on 28/03/2023.
//
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

stack_t *createStack(){
    stack_t *s = malloc(sizeof(stack_t));
    s->data = malloc(10 * sizeof(float));
    s->size = 0;
    s->capacity = 10;
    s->error = 0;
    return s;
}

char isEmpty(stack_t *s){
    return s->size == 0;
}

void push(stack_t *s, float value){
    for(int i = 0;i<= s->size;i++){
        s->data[i] = 1;
    }
}

float top(stack_t *s){
    return s->data[s->size];
}

void pop(stack_t *s){

}

char getError(stack_t *s){
    return s->error;
}

void destroyStack(stack_t *s){
    free(s->data);
    free(s);
}