#include <stdio.h>
#include <math.h>

double root(double a){
    double result = 0;
    double solution = sqrt(a);
    double i = 1;
    do{
        result = i * i;
        i = i + 0.001;
    } while (solution >= result);
    i = i -1;
    return i;
}

int main(void) {
    double Zahl = 0;
    double solution = 0;
    printf("Geben sie eine Zahl an von der Sie die Wurzel Ziehen wollen: ");
    scanf(" %lf", &Zahl);
    double results = root(Zahl);
    printf("%lf", results);
    return 0;
}
