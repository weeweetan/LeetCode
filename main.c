#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include "func.h"
#define product(x) (x*x)
int main(int argc, char *argv[]) {

/*
 * 001两个整数之和测试用例
 * int nums[] = {2,7,11,15};
 * int *retval=NULL;
 * retval=twoSum(nums, 4, 26);
 * printf("[%d,%d]\n", *(retval+0), *(retval+1));
 *
 */


/*  002 两数之和测试用例
 *  long long num1 = 0, num2 = 0;
    int mod = 0;
    static struct ListNode* l1 = NULL;
    static struct ListNode* l2 = NULL;
    static struct ListNode* l3 = NULL;
    struct ListNode* node1;
    struct ListNode* temp1;
    struct ListNode* node2;
    struct ListNode* temp2;
    printf("please input the first number: ");
    scanf("%lld", &num1);
    printf("please input the second number: ");
    scanf("%lld", &num2);

    if (num1 == 0)
    {
        l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
        l1->val = 0;
        l1->next=NULL;
    }
    while (num1 != 0)
    {
        mod = num1 % 10;
        node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
        node1->val = mod;
        node1->next = NULL;
        temp1 = l1;
        if (l1 == NULL)
        {
            l1 = node1;
            node1->next = NULL;
        }
        else
        {
            while (temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = node1;
        }
        num1 /= 10;
    }
    mod = 0;
    if (num2 == 0)
    {
        l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        l2->val = 0;
        l2->next=NULL;
    }
    while (num2 != 0)
    {
        mod = num2 % 10;
        node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        node2->val = mod;
        node2->next = NULL;
        temp2 = l2;
        if (l2 == NULL)
        {
            l2 = node2;
            node2->next = NULL;
        }
        else
        {
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = node2;
        }
        num2 /= 10;
    }

    l3 = addTwoNumbers(l1, l2);
    printf("\n");
    while (l3 != NULL)
    {
        printf("%d",l3->val);
        l3 = l3->next;
    }*/

/*
 * 003 无重复最长字串
 * char temp[10] = {"pwwkew"};
    int result = 0;
    result = lengthOfLongestSubstring(temp);
    printf("%d\n", result);*/
/*
 * 007数字反转测试用例
 * int result = reverse(123);
 * printf("%d\n", result);
 *
 */

/*
 *009 回文数
 * bool result = isPalindrome(-121);
 * printf("%d", result);
 * return 0;
 */

/*
 * 013 罗马数字转整数
 * int result = romanToInt(argv[1]);
    printf("%d", result);*/

//    char * strs[3] = {"flower","flow","flight"};
//    char * strs[3] = {"dog","racecar","car"};
//    char * strs[3] = {"strcpy","strlen","strtok"};
//    char * strs[2] = {"a", "ac"};
//    char * result  = longestCommonPrefix(strs, 2);
//    printf("%s\n", result);
//    free(result);
//    bool result = isValid("(])");
//    printf("%d\n", result);
//    printHeart();
//    int i = 3, j = 0, k = 0;
//    j = product(i++);
//    k = product(++i);
//    printf("j=%d,k=%d",j,k);
    int temp[] = {-50,-50,-50,-50,-49,-48,-48,-48,-48,-47,-47,-46,-45,-43,-43,-43,-42,-41,-41,-41,-41,-41,-41,-40,-40,-39,-39,-39,-38,-38,-37,-37,-36,-35,-30,-29,-29,-29,-28,-27,-27,-27,-26,-24,-22,-22,-22,-21,-21,-21,-21,-21,-20,-20,-19,-19,-18,-17,-15,-15,-12,-12,-11,-9,-8,-8,-7,-7,-7,-6,-5,-5,-4,-4,-3,-3,-3,-2,-1,-1,-1,0,0,0,0,0,1,2,2,2,2,5,6,6,7,8,9,10,10,11,11,11,11,14,14,14,15,16,19,19,21,21,23,25,25,26,26,26,27,28,29,29,29,29,30,30,31,32,32,32,33,33,35,35,36,36,37,37,37,38,38,39,39,39,40,40,40,41,41,41,42,42,42,42,42,44,44,47,48,48,50,50};
//    int temp[16] = {0,0,0,1,1,1,1,2,2,3,3,4,4,4,5,6};
//    printf("%d",strlen(temp));
    int ret = removeDuplicates(temp, 162);
    printf("ret:%d\n", ret);
    for (int i = 0; i < ret; ++i) {
        printf("%d\n", temp[i]);
    }
}

