#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

struct list {
    void **value;
    int nmemb;
    int next;
    char error;
    int esize;
};

list_t *create(int nmemb, int esize) {
    list_t *l;
    l = (list_t *) malloc(sizeof(list_t));
    l->next = 0;
    l->nmemb = nmemb;
    l->esize = esize;
    l->error = 0;
    l->value = (void **) calloc(nmemb, sizeof(void *));
    return l;
}

// private !
static char isFull(list_t *l) {
    return l->next == l->nmemb;
}

// private
static void increase(list_t *l) {
    l->nmemb *= 2;
    l->value = (void **) realloc(l->value,
                                 l->nmemb * sizeof(void *));
}

void append(list_t *l, void *val) {
    void *elem;
    if (isFull(l))
        increase(l);
    elem = malloc(l->esize);
    memcpy(elem, val, l->esize);
    l->value[l->next] = elem;
    l->next += 1;
}

void *getValueAt(list_t *l, int pos) {
    if (pos < 0 || pos >= l->next) {
        l->error = 1;
        return NULL;
    }
    return l->value[pos]; // oder Kopie liefern ?
}

char getError(list_t *l) {
    return l->error;
}

void destroy(list_t *l) {
    int i;
    for (i = 0; i < l->next; i++)
        free(l->value[i]);
    free(l->value);
    free(l);
}