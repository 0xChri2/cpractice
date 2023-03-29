#ifndef LISTE_H
#define LISTE_H

//====================================
// incomplete data type
// ( forward declaration )
//====================================
typedef struct list list_t;

//====================================
// interface
//====================================
list_t *create(int nmemb, int esize);
void append(list_t *l, void *val);
void *getValueAt(list_t *l, int pos);
char getError(list_t *l);
void destroy(list_t *l);

#endif //LISTE_H


