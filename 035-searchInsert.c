//
// Created by 11135 on 2019/4/2.
//
#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
    int low, high, mid;
    low = 0;
    high = numsSize - 1;
    mid = numsSize / 2;

    while (low < high)
    {
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            low = mid;
            mid = mid + (high - low) / 2;
        } else {
            high = mid;
            mid = mid - (high - low) / 2;
        }
    }
    return -1;
}


int insert(int* nums, int numsSize, int target)
{
    int low, high, mid;
    low = 0;
    high = numsSize - 1;
    mid = numsSize / 2;

    while (low < high)
    {
        if (nums[mid] > target) {
            low = mid;
            mid = mid + (high - low) / 2;
            if (nums[mid+1] > target) {

            }
        } else {
            high = mid;
            mid = mid - (high - low) / 2;
        }
    }
}


int searchInsert(int* nums, int numsSize, int target) {
    int low, high, mid;
    if (numsSize == 1)
    {
        if (*nums >= target) {
            return 0;
        } else {
            return 1;
        }
    }

    if (target > nums[numsSize-1])
    {
        return numsSize;
    }

    low = 0;
    high = numsSize - 1;

    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            high = mid;
        } else {
            low = mid+1;
        }
    }

    return low;

}


int main(int argc, char **argv)
{
//    int temp[] = {1,3,5,6};
    int temp[] = {1,3,5,6};
    int result = searchInsert(temp, 4, 2);
    printf("result:%d", result);
}