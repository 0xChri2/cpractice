# include <stdio.h>
# include "bruch.h"


int main ( void ) {
// ein Array von f¨u nf Br ¨u chen :
/*addieren
    bruch_t werte [5] = {{1 ,2} , {1 ,3} , {1 ,4} , {1 ,5} , {1 ,6}};
    bruch_t result = summe(werte , 5); // Array als Parameter




    char s [32] , str [5][32]; // Zeichenketten
    for (int i = 0; i < 5; i ++)
        btos( werte [i], str [i], 32); // bruch -to - string
    btos(result ,s ,32);

    printf ("% s + % s + % s + %s + %s = %s \n" , str [0] , str [1] ,str [2] , str [3] , str [4] , s );
*/
//subtahieren
    bruch_t subtra [2] = {{5 ,4} , {2 ,6}};
    bruch_t result = subsum(subtra, 2);

    char s[32], str[5][32];
    for(int i = 0;i < 2;i++)
        btos(subtra[i], str[i],32);
    btos(result,s,32);

    printf ("% s - % s = %s \n" , str [0] , str [1] , s );
    return 0;
}