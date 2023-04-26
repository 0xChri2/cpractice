#include <iostream>
#include "heap.h"
using namespace std;

int main() {
    heap heap(10);
    heap.insert(2);
    printf("Test val: %i\n", heap._data[0]);
    printf("min ist: %i\n", heap.minimum());
    printf("Error ist: %i\n", heap.getError());
    //printf("ToString ist: %s \n", heap.toString(heap));
    heap.extractMin();
   // printf("Extractmin ist: %s \n", heap.toString(heap.extractMin()));
    heap.~heap();
    return 0;
}
