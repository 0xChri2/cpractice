#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("test.txt","a");
    if(fp == NULL)
    {
        printf("File open fail");
    }
    fprintf(fp,"Hello World");
    char* data = "Nix, Garnichts";
    fputs(data,fp);
    return 0;
}
