#include <stdio.h>
#include <math.h>

// maximum number of points
#define MAX_POINTS 100

int main( void ) {

    // --- print program header
    printf("Programm zur Berechnung von Polygonen\n");
    printf("-------------------------------------\n");

    // --- read points from input
    int n;
    double x[MAX_POINTS];
    double y[MAX_POINTS];

    printf("Wieviel Punkte hat das Polygon? ");
    scanf("%d", &n);
    printf("%d\n", n);

    for(int i=0; i < n; i++) {
        printf("Punkt %d im Format x/y? ", i);
        scanf("%lf/%lf", &x[i], &y[i]);
        printf("%.2lf/%.2lf\n", x[i], y[i]);
    }

    // --- edges and circumference
    double circumference = 0.0;

    // TODO

    // --- compute the area
    double area = 0.0;

    // TODO

    // --- compute the centroid
    double x_centroid = 0.0;
    double y_centroid = 0.0;


    // TODO

    // --- check whether centroid is inside
    unsigned inside = 0;

    // TODO

    // --- output results
    printf("\nErgebnisse:\n");
    printf("-----------\n");
    printf("Anzahl Eckpunkte: %d\n", n);

    // Kanten
    for (int i = 0; i < n; ++i)
    {

        int j = i +1;
        if(j == n)
        {
            j = 0;
        }
        double lenght = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j],2));

        //circumference
        circumference += lenght;

        area += (y[i] + y[j]) * (x[i] - x[j]);
        printf("Kante %i von %.2lf/%.2lf nach %.2lf/%.2lf mit Laenge %.2lf\n", i, x[i], y[i], x[j], y[j], lenght);
    }
    area *= 0.5;

    for (int i = 0; i < n; ++i)
    {
        int j = i +1;
        if(j == n)
        {
            j = 0;
        }
        x_centroid += (x[i] + x[j]) * (x[i] * y[j] - x[j] * y[i]);
        y_centroid += (y[i] + y[j]) * (x[i] * y[j] - x[j] * y[i]);
    }
    double sechs = 6.0;
    x_centroid *= 1/(sechs * area);
    y_centroid *= 1/(sechs * area);

    printf("Umfang: %.2lf\n", circumference);
    printf("Flaecheninhalt: %.2lf\n", area);
    printf("Schwerpunkt: %.2lf/%.2lf\n", x_centroid, y_centroid);
    printf("Schwerpunkt drinnen? %d\n",inside);

    return 0;
}

