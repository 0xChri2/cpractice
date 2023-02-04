#include <stdio.h>

void countDigitsAndLetters(char* string, int* digit, int* letters){
    for (int i = 0; string[i] != 0; i++) {
        if(string[i] >= '0' && string[i] <= '9'){
            *digit = *digit +1;
        }
        else if((string[i]>='a' && string[i] <= 'z') || (string[i]>='A' && string[i] <= 'Z')) {
            *letters = *letters + 1;
        }

    }
}

int main() {
    const char* string = {"Hallo 12 Welt"};
    int digit = 0,letters = 0;
    countDigitsAndLetters(string,&digit,&letters);
    printf("String: %s , Digits: %d, Letters: %d", string, digit, letters);
    return 0;
}
