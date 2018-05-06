//
// Created by 11135 on 2018/5/6.
//
#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#define DEAL(l)             \
    if (l != NULL)         \
{                           \
while (l != NULL) {        \
node = (struct ListNode *) malloc(sizeof(struct ListNode)); \
sum = l->val;  \
if (flag)       \
sum += 1;       \
if (sum > 9)    \
{               \
mod = sum % 10; \
flag = 1;       \
} else {        \
mod = sum;      \
flag = 0;       \
}               \
node->val = mod;    \
node->next = NULL;  \
temp = result;       \
                        \
while (temp->next != NULL) {    \
temp = temp->next;  \
}                   \
temp->next = node;  \
l = l->next;      \
}                   \
}                   \

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
/*  方案1不理想
    struct ListNode* result = NULL;
    struct ListNode* node = NULL;
    struct ListNode* temp = NULL;
    unsigned long long num1 = 0, num2 = 0, sum = 0, mod = 0, counter = 0;

    while (l1 != NULL)
    {

        num1 = num1 + (l1->val)*pow(10,counter);
        counter++;
        l1 = l1->next;
    }

    counter = 0;
    while (l2 != NULL)
    {
        num2 = num2 + (l2->val)*pow(10,counter);
        counter++;
        l2 = l2->next;
    }

    sum = num1 + num2;

    if (sum == 0)
    {
        result = (struct ListNode*)malloc(sizeof(struct ListNode));
        result->val = sum;
        result->next = NULL;
    }
    while (sum != 0)
    {
        mod = sum % 10;
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = mod;
        node->next = NULL;
        temp = result;
        if (result == NULL)
        {
            result = node;
            node->next = NULL;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
        sum /= 10;
    }
    return result;*/

    struct ListNode* result = NULL;
    struct ListNode* node = NULL;
    struct ListNode* temp = NULL;
    int sum = 0, mod = 0, flag = 0;
    while (l1 != NULL && l2 != NULL) {
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
        sum = l1->val + l2->val;
        if (flag)
            sum += 1;
        if (sum > 9)
        {
            mod = sum % 10;
            flag = 1;
        }
        else {
            mod = sum;
            flag = 0;
        }

        node->val = mod;
        node->next = NULL;
        temp = result;
        if (result == NULL)
        {
            result = node;
            node->next = NULL;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    DEAL(l1)
/*    if (l1 != NULL)
    {
        while (l1 != NULL) {
            node = (struct ListNode *) malloc(sizeof(struct ListNode));
            sum = l1->val;
            if (flag)
                sum += 1;
            if (sum > 9)
            {
                mod = sum % 10;
                flag = 1;
            } else {
                mod = sum;
                flag = 0;
            }
            node->val = mod;
            node->next = NULL;
            temp = result;

            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
            l1 = l1->next;
        }
    }*/
    DEAL(l2)
/*    if (l2 != NULL)
    {
        while (l2 != NULL) {
            node = (struct ListNode *) malloc(sizeof(struct ListNode));
            sum = l2->val;
            if (flag)
                sum += 1;
            if (sum > 9)
            {
                mod = sum % 10;
                flag = 1;
            } else {
                mod = sum;
                flag = 0;
            }
            node->val = mod;
            node->next = NULL;
            temp = result;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
            l2 = l2->next;
        }
    }*/

    if (flag) {
        node = (struct ListNode *) malloc(sizeof(struct ListNode));
        node->val = 1;
        node->next = NULL;
        temp = result;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    return result;
}
