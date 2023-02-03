#include <stdio.h>

double normal(int n){
    double result = 0;
    for(int i = 1; i<=n;i++){
        result= result + (1.00/i);
    }
    return result;
}

double rekursiv(int n){
    if(n==1)return 1;
    return rekursiv(n -1) + (1.00/n);;
}


int main(void) {
    int n = 42;
    printf ("normal(%d) =%g\n", n, normal (n));
    printf ("rekursiv(%d)=%g\n", n, rekursiv (n));
    return 0;
}