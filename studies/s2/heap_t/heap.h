//
// Created by Christoph Riedel on 03.04.23.
//

#ifndef HEAP_T_HEAP_H
#define HEAP_T_HEAP_H
typedef struct{
    int *data;
    int error;
    int size;
    int min;
}heap_t;

heap_t *createHeap();
char insert(heap_t *h, int val);
int minimum(heap_t *h);
char extractMin(heap_t *h);
char getError(heap_t *h);
char* toString(heap_t *h);
void destroyHeap(heap_t *h);

#endif //HEAP_T_HEAP_H
