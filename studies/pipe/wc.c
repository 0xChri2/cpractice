#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*int main( int argc, char* argv[] ) {
  // Allocate enough space for the command string
  char command[1024];

  // Initialize the command string to an empty string
  command[0] = '\0';

  // Concatenate the "wc" command and the filename
  strncat(command, "wc ", sizeof(command) - strlen(command) - 1);
  strncat(command, argv[1], sizeof(command) - strlen(command) - 1);

  // Null-terminate the command string
  command[sizeof(command) - 1] = '\0';

  // Execute the command
  system(command);

  return 0;
}*/
int main(int argc, char* argv[]){
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
            
            //count words 
            

        }while (!feof(open));
      
        
        fclose(open);
    }
}