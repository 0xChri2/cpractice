#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main() {

    stack_t *stack = createStack();
    char input[100];
    printf("Enter an expression in reverse Polish notation: ");
    fgets(input,100,stdin);
    

}
