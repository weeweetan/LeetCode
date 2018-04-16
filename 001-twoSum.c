//
// Created by 11135 on 2018/4/14.
//
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int *reval = (int *)malloc(sizeof(int)*2);
    for (i = 0; i<numsSize;i++) {
        for (j=i+1; j<numsSize; j++) {
            if (*(nums+i)+*(nums+j)==target) {
                *(reval+0) = i;
                *(reval+1) = j;
                return reval;
            }
        }
    }
    return reval;
}