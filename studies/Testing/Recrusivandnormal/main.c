/*#include <stdio.h>

int normal(int n){
    int sum = 0;
    for(int i = 0;i<=n;i++){
        sum = sum + i;
    }
    return sum;
}

int rekursiv(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + rekursiv(n - 1);
    }
}

int main(void) {
    //int long = 3467567L;
    int n = 3;
    printf ("\n=%d normal(n)=%ld\n", n, normal (n));
    printf ("\n=%d rekursiv(n)=%ld\n", n, rekursiv (n));
    return 0;
}reliefpfeiler*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int palindromfunc(char* kandidat,int start, int end,int lenght){
    char* revword =(char*) malloc(lenght * sizeof(char));
    int i=0;
    for(i=0;i <= (lenght-1);i++){
        revword[i] = kandidat[lenght -1 -i];
    }
    revword[i +1] = '\0';
    for(int j = 0; j<= (lenght-1);j++){
        if(revword[j] != kandidat[j]){
            return 0;
            break;
        }
    }
    return 1;
}
int palindromrev(char* kandidat, int start, int end){
    if(start >= end){
        return 1;
    }
    else if(kandidat[start] != kandidat[end]){
        return 0;
    }
    return palindromrev(kandidat, (start+1), (end-1));

}

int main () {
    int i = 0;
    char * kandidat = "otto" ;
    int palindrom =0 ;
    int lenght = strlen(kandidat);
    palindrom = palindromrev(kandidat, 0,lenght-1);
    if(palindrom){
    printf ( "%s ist ein Palindrom !\n" , kandidat );
    }else{
    printf ( "%s ist KEIN Palindrom!\n" , kandidat );
    }
    return 0;
}
