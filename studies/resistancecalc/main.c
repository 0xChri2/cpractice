
#include <stdio.h>
#include <math.h>


int read_e_series() {
    while(1) {
        int n;
        printf("E-Reihe: ");
        scanf("%i",&n);
        if (n==6 || n==12 || n==24 || n==48 || n==96 || n==192) return n;

        printf("ungueltige Eingabe (%i)!\n",n);
    }
}


int read_decade() {
    int n;
    printf("Dekadenfaktor: ");
    scanf("%i",&n);
    return n;
}


double compute_tolerance( int e ) {
    // TODO
    switch (e) {
        case 6:
            return 0.20;
        case 12:
            return 0.10;
        case 24:
            return 0.05;
        case 48:
            return 0.02;
        case 96:
            return 0.01;
        case 192:
            return 0.005;
    }
}


void compute_set_values( int e_series, int decade, double table[] ) {
    // TODO
    double j = 0;
    for(int i = 0; i< e_series;i++ ) {
        table[i] = pow(10, j / e_series) * pow(10, decade);
        j++;
    }
}


void print_encoding( int e_series, double set_value, double tolerance ) {
    // TODO
    printf("-");
    printf("-");
    printf("-");
    printf("-");
}


int main() {
    // lese gewuenschte E-Reihe und Dekade
    int e_series = read_e_series();
    int decade = read_decade();
    
    // bestimme erst die Toleranz und dann die Nennwerte
    double table[192];
    double tolerance = compute_tolerance(e_series);
    compute_set_values(e_series, decade, table);

    // gebe alle Werte mit Kodierung und Toleranzen aus
    for (int i = 0; i < e_series; i++) {
        // TODO
        double set_value = table[i];
        double lower_bound = 0.0;
        double upper_bound = 0.0;
        printf("%.2lf ", set_value);
        print_encoding(e_series, set_value, tolerance);
        printf(" (%.2lf - %.2lf)\n", lower_bound, upper_bound);
    }
}
