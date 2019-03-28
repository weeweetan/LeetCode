//
// Created by 11135 on 2019/3/20.
//
#include <stdio.h>
/*int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}*/
int removeElement(int *nums, int numsSize, int val)
{
    int i = 0;
    while (i < numsSize) {
        if (nums[i] == val) {
            nums[i] = nums[numsSize - 1];
            // reduce array size by one
            numsSize--;
        } else {
            i++;
        }
    }
    return numsSize;
}

int main(int argc, char *argv[])
{
    int temp[] = {0,1,2,2,3,0,4,2};
    int result = removeElement(temp, 8, 2);
    printf("%d\n", result);
}