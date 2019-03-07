#include <stdio.h>

//
// Created by 11135 on 2018/9/30.
//
//int removeDuplicates(int *nums, int numsSize) {
//    if (numsSize <= 1) {
//        return numsSize;
//    }
//
//    int i = 0, j, count = 1;
//    while (i < numsSize) {
//        for (j = i + 1; j < numsSize && nums[i] == nums[j]; j++) {}
//        if (j < numsSize) {
//            nums[count++] = nums[j];
//        }
//        i = j;
//    }
//
//    return count;
//}

int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
    {
        return 0;
    }

    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i])
        {
            i++;
            nums[i] = nums[j];
        }
    }

    return i+1;

}


int main(int argc, char *argv[])
{
    int temp[] = {-50,-50,-50,-50,-49,-48,-48,-48,-48,-47,-47,-46,-45,-43,-43,-43,-42,-41,-41,-41,-41,-41,-41,-40,-40,-39,-39,-39,-38,-38,-37,-37,-36,-35,-30,-29,-29,-29,-28,-27,-27,-27,-26,-24,-22,-22,-22,-21,-21,-21,-21,-21,-20,-20,-19,-19,-18,-17,-15,-15,-12,-12,-11,-9,-8,-8,-7,-7,-7,-6,-5,-5,-4,-4,-3,-3,-3,-2,-1,-1,-1,0,0,0,0,0,1,2,2,2,2,5,6,6,7,8,9,10,10,11,11,11,11,14,14,14,15,16,19,19,21,21,23,25,25,26,26,26,27,28,29,29,29,29,30,30,31,32,32,32,33,33,35,35,36,36,37,37,37,38,38,39,39,39,40,40,40,41,41,41,42,42,42,42,42,44,44,47,48,48,50,50};
    int ret = removeDuplicates(temp, 162);
    printf("ret:%d\n", ret);
    for (int i = 0; i < ret; ++i) {
        printf("%d\n", temp[i]);
    }
}