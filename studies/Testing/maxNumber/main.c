#include <stdio.h>

int maxNumb(int *array){
    int max = 0;
    for(int i = 0;i <= (sizeof(array) / sizeof(array)[0]);i++){
        if(max < array[i]){
            max = array[i];
        }
    }
    return max;
}

int main() {
    int array[]= {1,3,23,5,9,8,7};
    int max = maxNumb(&array);
    printf("Die Maximale Zahl ist %d",max);
}
