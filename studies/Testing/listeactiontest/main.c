#include <stdio.h>
#include "liste.h"

int main(void) {
    printf("List of int values:\n");

    int i;
    list_t *li, *ld;

    li = create(2, sizeof(int)); // list of int - values !!!
    for (i = 1; i <= 10; i++)
        append(li, &i);

    for (i = 0; i < 20 && !getError(li); i++) {
        void *val = getValueAt(li, i);
        if (getError(li) == 0)
            printf(" %d : %d \n", i, *(int *) val);
    }
    destroy(li);

    printf("\n\nList of double values:\n");
    double f;
    ld = create(2, sizeof(double)); // list of double - values !!
    for (i = 1, f = 1.25; i <= 10; i++, f += 0.25)
        append(ld, &f);

    for (i = 0; i < 20 && !getError(ld); i++) {
        void *val = getValueAt(ld, i);

        if (getError(ld) == 0) {
            double fval = *(double *) val;
            printf(" %d : %f \n", i, fval);
        }

    }
    destroy(ld);

    return 0;
}