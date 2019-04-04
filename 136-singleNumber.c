//
// Created by 11135 on 2019/4/3.
//
#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int temp = 0;
    for (int i = 0; i < numsSize; ++i) {
        temp = temp ^ nums[i];
    }
    return temp;
}

int main(int argc, char **argv) {
    int temp[] = {4,1,2,1,2};
    int result = singleNumber(temp, 5);
    printf("%d", result);
}