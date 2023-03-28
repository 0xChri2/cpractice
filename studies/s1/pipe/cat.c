
#include <stdio.h>

/**
 * print the file
 * @param f given file
 */
void catFile(FILE *f) {
    int cur;

    while( 1 ) {
        cur = fgetc( f );
        if( cur == EOF )
            break;
        fputc( cur, stdout );
    }
}

int main( int argc, char* argv[] ) {
    if( argc == 1 ) {
        catFile(stdin);
    } else {
        for( int i=1; i<argc; i++ ) {
            FILE *f = fopen(argv[i], "r");
            if( f == NULL )
                perror(argv[i]);
            else {
                catFile(f);
            }
        }
    }
    return 0;
}
