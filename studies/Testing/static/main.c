/*#include <stdio.h>

void foo()
{
    int a = 10;
    static int sa = 10;

    a += 5;
    sa += 5;

    printf("a = %d, sa = %d\n", a, sa);
}


int main() {
    int i;

    for (i = 0; i < 10; ++i)
        foo();
}*/
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
