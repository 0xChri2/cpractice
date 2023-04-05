//
// Created by Christoph Riedel on 03.04.23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

heap_t *createHeap(){
    heap_t *h = malloc(sizeof(heap_t));
    h->data = (int*) malloc(sizeof(int) *10);
    h->size = 10;
    h->min = 0;
    return h;
}

char insert(heap_t *h, int val){
    if (h->min < h->size) {
        h->data[h->min] = val;
    }
    else{
        h->size = val;
        h->data = realloc(h->data, h->size * sizeof(int));
    }
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
    char *str = malloc(sizeof(char) * h->size);
    int len = 0;
    char buf[h->size];
    for(int i =0;i< h->size;i++){
        sprintf(buf,"%d", h->data);
    }
    strcat(str,buf);
    return str;


}

void destroyHeap(heap_t *h){
    free(h);
    free(h->data);
}