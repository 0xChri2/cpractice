#include <stdio.h>
#include <stdlib.h>

//leetcode Problem

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    returnSize = (int*) malloc(sizeof(int) * 2);
    for(int i = 0; i < numsSize;i++){
        for(int j = i+1; j < numsSize;j++){
            int sum = nums[i]+ nums[j];
            if(target == sum){
                returnSize[0] = i;
                returnSize[1] = j;
                return returnSize;
            }
        }
    }
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize = 0;
    int *result = twoSum(nums, 4, target, &returnSize);
    if(result != NULL){
        printf("[%d, %d]\n", result[0], result[1]);
    }else{
        printf("Keine Loesung gefunden.\n");
    }
    free(result);
    return 0;
}