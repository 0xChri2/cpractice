#include <stdio.h>
int error(int i)
{
    int error = 1;
    if(i == 1 || i == 2 || i == 3 || i ==4 || i == 0)
    {
        error = 0;
    }
    return error;
}

int main() {

    // inputs: temperature and its unit
    int unitIn;
    double tempIn;
    // output: converted temperature
    int unitOut;
    double tempOut;

    int error1 = 0;
    int error2 = 0;

    // print banner
    printf("\n");
    printf("Programm zur Umrechnung von Temperaturen\n");
    printf("----------------------------------------\n");

    // repeat until user wants to end
    do {
        do {

            // step 1: read input unit
            printf("\nAus welchem Einheitensystem soll umgerechnet werden?\n");
            printf("1: grad C     2: grad F     3: K    0: Programmende\n");
            printf("Ihre Wahl: ");
            scanf("%d", &unitIn);
            error1 = error(unitIn); //check if wrong Answer
            printf("%d\n", unitIn);
        } while(error1 != 0);
        if(unitIn == 0)
        {
            break;
        }

        // step 2: read input temperature
        printf("\nBitte geben Sie die umzurechnende Temperatur an: ");
        scanf("%lf", &tempIn);
        printf("%lf\n",tempIn);

        // step 3: read output unit
        do {
            printf("\nIn welches Einheitensystem soll umgerechnet werden?\n");
            printf("1: grad C     2: grad F     3: K\n");
            printf("Ihre Wahl: ");
            scanf("%d", &unitOut);
            error2 = error(unitOut); //check if wrong Answer
            printf("%d\n", unitOut);
        }while(error2 != 0);
        // step 4: first convert the input value to (deg Celsius)
        double tempCelsius;
        switch (unitIn) {
            case 1: tempCelsius = tempIn;
                printf("\n%.2lf grad C = ", tempIn);
                break;
            case 2: tempCelsius = (tempIn - 32) * 5/9;
                printf("\n%.2lf grad F = ", tempIn);
                break;
            case 3: tempCelsius = tempIn - 273.15;
                printf("\n%.2lf K = ", tempIn);
                break;
            case 4: tempOut = (tempCelsius - 7.5) / 0.525;
                printf("%.2lf Rømer\n");
            case 0:
                break;
            default:
                printf("\nKeine Ausgangseinheit ausgewaehlt.\n");
        }

        // step 5: now convert the intermediate value to the target value
        switch (unitOut) {
            case 1: tempOut = tempCelsius;
                printf("%.2lf grad C\n", tempOut);
                break;
            case 2: tempOut = (tempCelsius * 9/5) + 32;
                printf("%.2lf grad F\n", tempOut);
                break;
            case 3: tempOut = tempCelsius + 273.15;
                printf("%.2lf K\n", tempOut);
                break;
            case 4: tempOut = tempCelsius * 0.525 +7.5;
                printf("%.2lf Rømer\n");
            default:
                printf("\nKeine Zieleinheit ausgewaehlt.\n");
        }

        // step 6: print graphical result
        printf("==================================================\n");
        printf("\n");
        for(int k = 1; k <= (tempCelsius / 2);k++)
        {
            printf("#");
        }
        printf("\n\n");
        printf("==================================================\n");
        printf("0 grad C                                 100 grad C\n");
        printf("\n");

    } while (unitIn != 0);
}

