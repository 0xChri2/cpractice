//
// Created by Christoph Riedel on 03.04.23.
//
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

heap_t *createHeap(){
    heap_t *h = malloc(sizeof(heap_t));
    h->data = (int) malloc(sizeof(int) *10);
    h->size = 10;
    h->min = 1;
    return h;
}

char insert(heap_t *h, int val){
    if(val < h->size){
        h->size = val;
    }
    h->data = realloc(h->data, sizeof(int) * h->size);
    h->data = val;
}

int minimum(heap_t *h){
    return h->data[h->min];
}

char extractMin(heap_t *h){

}

char getError(heap_t *h){
    return h->error;
}

char* toString(heap_t *h){
    char *str[100];
    sprintf(str,"%d", h->data);
    return str;
}

void destroyHeap(heap_t *h){
    free(h);
    free(h->data);
}