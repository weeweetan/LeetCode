#include <stdio.h>

//
// Created by 11135 on 2018/9/30.
//
int removeDuplicates(int* nums, int numsSize) {
    int length = 0;
    for (int i = 0; i < numsSize; i++) {
        int flag = nums[i];
        printf("flag:%d, i:%d\n", flag, i);
        for (int j = i+1; j < numsSize; j++) {
            printf("nums[j]:%d, j:%d\n", nums[j], j);
            if (flag==nums[j]) {
                for (int k = j+1; k < numsSize; k++) {
                    printf("nums[k-1]:%d, nums[k]:%d\n", nums[k-1], nums[k]);
                    nums[k-1] = nums[k];
                }
                length++;
//                i--;
            }
        }
    }
    return length;
}
