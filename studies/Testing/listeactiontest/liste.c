#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

struct list {
    int size, next, *values;
    char error;
};

list_t *create(void) {
    list_t *l;
    l = (list_t *) calloc(1, sizeof(list_t));

    l->size = 8;
    l->next = 0;
    l->values = (int *) calloc(8, sizeof(int));
    l->error = 0;

    return l;
}

// private !
static char isFull(list_t *l) {
    return l->size == l->next;
}

// private !
static void increase(list_t *l) {
    l->size *= 2;
    l->values = (int *) realloc(l->values,
                                l->size * sizeof(int));
}

void append(list_t *l, int val) {
    if (isFull(l))
        increase(l);
    l->values[l->next] = val;
    l->next += 1;
}

// private !
static int find(list_t *l, int val) {
    int pos;
    for (pos = 0; pos < l->next; pos++)
        if (l->values[pos] == val)
            return pos;
    return -1;
}

// private !
static void decrease(list_t *l) {
    l->size /= 2;
    l->values = (int *) realloc(l->values,
                                l->size * sizeof(int));
}

void erase(list_t *l, int val) {
    int pos = find(l, val);
    if (pos == -1)
        return;
    for (; pos < l->next - 1; pos++)
        l->values[pos] = l->values[pos + 1];
    l->next -= 1;
    if (l->next < l->size / 4)
        decrease(l);
}

int getValueAt(list_t *l, int pos) {
    if (pos < 0 || pos >= l->next) {
        l->error = 1;
        return -1;
    }
    return l->values[pos];
}

char getError(list_t *l) {
    return l->error;
}

void destroy(list_t *l) {
    free(l->values);
    free(l);
}

void toScreen(list_t *l) {
    for (int i = 0; i < l->next; i++) {
        if (i > 0)
            printf(" , ");
        printf(" % d ", l->values[i]);
    }
    printf(" \n ");
}