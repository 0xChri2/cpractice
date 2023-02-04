#include <stdio.h>
#include <ctype.h>

int palindrom(char* string){
    char string2[20];
    int length =0;
    for(int i = 0;'\0' !=string[i];i++) {
        length++;
    }
    for(int i =0;i<=length-1;i++){
        if(isupper(string[i])){
            string[i] = tolower(string[i]);
        }
    }
    for(int i = 0;i<= (length-1);i++){
        string2[length -i -1] = string[i];
    }
    string2[length] = '\0';
    printf("%s\n",string2);
    for(int i =0;i <= length;i++){
        if(string2[i] != string[i]) {
            printf("Es ist kein Palindrom!");
            return 0;
        }
    }
    printf("Es ist ein Palindrom.");
    return 1;
}

int main() {
    char string[] = {"Otto"};
    palindrom(string);
}
