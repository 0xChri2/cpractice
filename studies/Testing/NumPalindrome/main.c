#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x){
   if (x < 0) {
        return false;
    }

    int reverse = 0;
    int n = x;
    while (n != 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }

    return (reverse == x);

}

int main() {
    int zahl = 121;
    bool result = isPalindrome(zahl);
    if(result == true){
        printf("Die Zahl %i ist ein Palindrom.", zahl);
    }else{
        printf("Die Zahl %i ist kein Palindrom", zahl);
    }
}
