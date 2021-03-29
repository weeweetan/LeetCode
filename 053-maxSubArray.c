//
// Created by 11135 on 2020/10/20.
//

#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
    return a > b ? a : b;
}



int maxSubArray(int* nums, int numsSize)
{
    int sub_sum = 0, max_sum = INT_MIN;
    for (int i = 0; i < numsSize; i++)
    {
        sub_sum += nums[i];
        if (sub_sum > max_sum)
            max_sum = sub_sum;
        if (sub_sum < 0) sub_sum = 0;
    }
    return max_sum;
}

int main(int argc, char **argv)
{
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d\n", maxSubArray(nums, sizeof(nums)/ sizeof(int)));
}