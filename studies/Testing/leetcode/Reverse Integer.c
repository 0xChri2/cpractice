int numlenght (int num){
    int len = 0;
    while (num != 0) {
        len++;
        num /= 10;
    }
    return len;
}

int reverse(int x){
    
    int len = numlenght(x);
    int *result = (int*) malloc(len * sizeof(int));
    for(int i = 0; i< len;i++){
       result[i] = x % 10;
       x /= 10;
    }
    long int reversed = 0;
    for(int i = 0; i < len; i++) {
        reversed = reversed * 10 + result[i];
    }
    free(result);

    if(reversed > 2147483647 | reversed < -2147483647){
        return 0;
    } else {    
        return reversed;
    }
}