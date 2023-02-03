#include <stdio.h>
void swap(int *b, int *a) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(void) {
    int array[6] = {4, 9, 21, 42};
    int i;
    swap(&array[3], &array[1]);
    for (i = 0; i < 6; i++) {
        printf("%d\n", array[i]);
    }
}