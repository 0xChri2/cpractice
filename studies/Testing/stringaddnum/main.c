#include <stdio.h>

char string[] = "Friday for future";

int main() {
    char* ptr = string + 3;
    printf("1: %s\n", string);
    printf("2: %s\n", ptr+4);
    printf("3: %c\n", (*string + 3));
    printf("4: %c\n", *(ptr++));
    printf("5: %s\n", ++ptr);
}