//
// Created by 11135 on 2020/1/12.
//
#include <stdio.h>
#include <math.h>

int findNumbers(int* nums, int numsSize)
{
    int count = 0, bitlen = 0;
    for (int i = 0; i < numsSize; ++i) {
        bitlen = (int)floor(log10(nums[i])) + 1;
        if (bitlen % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

int main(int argc, char **argv)
{
    int temp[] = {555,901,482,1771};
    printf("%d\n", findNumbers(temp, 4));
}