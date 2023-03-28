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
        for(int i = 0; i < 10; i++){
            fgets(buffer, sizeof(buffer), open);
            fputs(buffer, stdout);
        }
        fclose(open);
    }
    
}
