/* ----------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] ) {
     if ( argc >= 3 ) {
        printf("Usage: %s <path> <file>\n", argv[0]);
        exit(1);
    }
    else if( argc == 2 ) {
        FILE *open = fopen(argv[1], "r");
        if (open == NULL) {
            fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
        }
        char buffer[1024];
        int count = 0;
        do{
            count++;
            fgets(buffer, sizeof(buffer), open);
            printf("%i : %s", count, buffer);
        }while (!feof(open));
      
        
        fclose(open);
    }
}
