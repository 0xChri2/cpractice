#include <stdio.h>
#include <math.h>

int main() {
    int n = 0;
    printf("Bitte geben Sie Anzahl der verschiedenen Buchstaben und Zeichen an:\n");
    scanf("%d ", &n);
    int m = 0;
    printf("Bitte gebe Sie die Anzahl der Stellen an \n");
    scanf("%d", &m);
    int summe = pow(n, m);
    printf("Die Anzahl der Meoglichkeiten sind: %d", summe);
    return 0;
}
