#include <stdio.h>

int main() {
   int rows,columns = 0;
    printf("Geben sie die Anzahl der Zeilen und Spalten an: ");
    scanf("%d", &n);
    scanf("%d",&m);

    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(columns * sizeof(int));
    }


}

/*PE1 Musterklausur Nr 4 a
 * In C muss die Speicherallokation für eine Matrix explizit durchgeführt werden
 * , um die Größe und den Zugriff auf die Matrixelemente sicherzustellen.
 * Die Initialisierung einer Matrix erfolgt normalerweise durch das Reservieren von Speicher für jede Zeile der Matrix.

Um eine zweidimensionale Matrix dynamisch zu initialisieren,
 müssen Sie zuerst einen Pointer auf Pointer deklarieren, um auf die Zeilen der Matrix zu verweisen.
 Dann müssen Sie für jede Zeile einen separaten Speicherbereich reservieren, indem Sie die malloc-Funktion verwenden. Dies kann wie folgt aussehen:

int **matrix;
matrix = (int **) malloc(num_rows * sizeof(int *));
for (int i = 0; i < num_rows; i++) {
matrix[i] = (int *) malloc(num_cols * sizeof(int));
}

In diesem Code wird zuerst der Speicher für die Zeilen der Matrix reserviert und dann für jede Zeile ein separates Speicherfeld für die Spalten.
 So kann jedes Element der Matrix unabhängig voneinander adressiert und initialisiert werden.*/