#include <stdio.h>
#include <math.h>

int fak(int n){
    if(n > 1) {
        return n * fak(n-1);
    }else {
        return 1;
    }
}
/*double sinus_f(double x, int n){
    int i;
    double sin = 0.0;
    for (i=0;i<n;i++) {
        sin += pow(-1,i)*pow(x,2*i+1)/fak(2*i+1);
    }
    return sin;
}*/


int main() {
    int x = fak(5);
    printf("%i",x);
}
