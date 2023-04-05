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
    if(h->min >= h->size){
        h->error = 1;
        return -1;
    } else {
        int min = h->data[h->min];
        for(int i = h->min; i < h->size -1; i++){
            h->data[i] = h->data[i + 1];
        }
        h->size--;
        return min;
    }
}

char getError(heap_t *h){
    return h->error;
}

char* toString(heap_t *h){
    char *str = malloc(sizeof(char) * h->size);
    int len = 0;
    char buf[h->size];
    for(int i =0;i< h->size;i++){
        sprintf(buf,"%d", h->data[i]);
        strcat(str, buf);
        strcat(str, " ");
    }
    return str;


}

void destroyHeap(heap_t *h){
    free(h);
    free(h->data);

}