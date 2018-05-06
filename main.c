#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "func.h"
int main() {

/*
 * 001两个整数之和测试用例
 * int nums[] = {2,7,11,15};
 * int *retval=NULL;
 * retval=twoSum(nums, 4, 26);
 * printf("[%d,%d]\n", *(retval+0), *(retval+1));
 *
 */


    long long num1 = 0, num2 = 0;
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

/*    while (l1 != NULL)
    {
        printf("%d",l1->val);
        l1 = l1->next;
    }

    printf("\n");
    while (l2 != NULL)
    {
        printf("%d",l2->val);
        l2 = l2->next;
    }*/
    l3 = addTwoNumbers(l1, l2);
    printf("\n");
    while (l3 != NULL)
    {
        printf("%d",l3->val);
        l3 = l3->next;
    }

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



}