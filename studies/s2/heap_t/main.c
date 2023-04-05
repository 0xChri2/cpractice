#include <stdio.h>
#include "heap.h"
#include <stdlib.h>

int main() {

    heap_t *heap = createHeap();
    insert(heap, 2);
    printf("Test val: %i\n", heap->data[0]);
    printf("min ist: %i\n", minimum(heap));
    printf("Error ist: %i\n", getError(heap));
    printf("ToString ist: %s \n", toString(heap));
    extractMin(heap);
    printf("Extractmin ist: %s \n", toString(heap));
    destroyHeap(heap);
    return 0;
}
