#include <stdio.h>
#include "liste.h"

const char OK = 1;

// Black-Box Test: Ist insert() ok?
char test01(void) {
    list_t *l = create();
    append(l, 1);
    if (getValueAt(l, 0) != 1)
        return !OK;
    getValueAt(l, 1);
    if (getError(l) != 0)
        return OK;
    return !OK;
}


// Black-Box Test: Ist erase() ok?
char test02(void) {
    list_t *l = create();
    append(l, 1);
    erase(l, 1);
    if (getError(l) != 0)
        return !OK;
    getValueAt(l, 0);
    if (getError(l) != 0)
        return OK;
    return !OK;
}

// White-Box Test : Ist increase() ok ?
char test03(void) {
    list_t *l = create();
    for (int i = 0; i < 50; i++)
        append(l, i);
    for (int i = 0; i < 50; i++) {
        int val = getValueAt(l, i);
        if ((getError(l) != 0) || (val != i))
            return !OK;
    }
    return OK;
}

int main(void) {
    char error_code = 0;
    char last_test_return = 0;

    last_test_return = test01();
    if (OK == last_test_return)
        printf(" test01 passed \n");
    else
        printf(" !!! test01 failed !!!\n");
    error_code = error_code || !last_test_return;

    last_test_return = test02();
    if (OK == last_test_return)
        printf(" test02 passed \n");
    else
        printf(" !!! test02 failed !!!\n");
    error_code = error_code || !last_test_return;

    last_test_return = test03();
    if (OK == last_test_return)
        printf(" test03 passed \n");
    else
        printf(" !!! test03 failed !!!\n");
    error_code = error_code || !last_test_return;

    return error_code;
}