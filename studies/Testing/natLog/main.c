#include <stdio.h>
#include <math.h>

int natlog1(double z){
    double summand = 0;
    double summe = 0;
    double e = 1.0e-6;
    double x = z-1; //warum ????
    if((x > -1) && (x <=1)){
        double zaehler = x;
        double nenner = 1;
        do{
            zaehler = zaehler * (-x);
            nenner = nenner + 1;
            summand = zaehler / nenner;
            summe = summe + summand;
        }while (fabs(summand)> e);
    }
}

int natlog2(double z){
    double summand, faktor1, faktor2, c;
    unsigned nenner;
    double summe;
    if(z > 0){
        do{
            2/
        } while ();
    }
}
int main() {
    double x = 0;
    scanf("Geben sie ein x an:", &x);
}
