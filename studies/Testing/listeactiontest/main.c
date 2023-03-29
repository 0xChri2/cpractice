#include <stdio.h>
#include "liste.h"

int main(void) {
    int i;
    list_t *l;
    l = create();

    for (i = 1; i < 30; i++)
        append(l, i);

    toScreen(l);


    for (i = 1; i < 30; i += 2)
        erase(l, i);

    toScreen(l);

    i = getValueAt(l, 20);

    if (getError (l) == 0)
        printf(" value [%2d ] = %2d \n ", 20, i);
    else
        printf(" 20 out of range \n ");

    destroy(l);

    return 0;
}