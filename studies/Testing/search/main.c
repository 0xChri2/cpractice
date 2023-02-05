#include <stdio.h>

int countChar(char* string, char n){
    int count =0;
    for(int i =0;string[i] != 0;i++){
        if(string[i] == n){
            count++;
        }
    }
    return count;
}


int main() {
    printf("%d \n",countChar("Propellerheads", 'e'));
    printf("%d \n",countChar("Reliefpfeiler", 'R'));
    printf("%d \n",countChar("Ruppenduppes", 'p'));
}
