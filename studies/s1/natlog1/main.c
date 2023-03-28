#include <stdio.h>
#include <math.h>
int netlog1(double z, double epsilon, double summe);

int main() {
    double z=0;
    double epsilon = 0;
    double summe;
    double ausgabe = netlog1(0.5, 0.0001,summe);
    printf("%lf",ausgabe);
}

int netlog1(double z, double epsilon, double summe)
{
    double x = z -1;
    if((x > -1) && (x <= 1))
    {
        double zaehler = x;
        double nenner = 1;
        double summand =0;
        double absSummand;
        summe = zaehler / nenner;
        do{
            zaehler = zaehler * (-x);
            nenner = nenner +1 ;
            summand = zaehler / nenner;
            //absSummand = summand > 0 ? summand : summand * -1;
            summe = summe + summand;
        } while (fabs(summand) >= epsilon);
    }
    else{
        summe = 0;
    }
    return summe;
}