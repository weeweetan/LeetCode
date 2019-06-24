//
// Created by 11135 on 2019/3/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    // 类似归并排序中的合并过程
    struct ListNode *dummyHead = malloc(sizeof(struct ListNode));
    memset(dummyHead, 0, sizeof(struct ListNode));
    struct ListNode *cur = dummyHead;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        } else {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
    }
    // 任一为空，直接连接另一条链表
    if (l1 == NULL) {
        cur->next = l2;
    } else {
        cur->next = l1;
    }
    return dummyHead->next;
}

struct ListNode* generate(int size)
{
    struct ListNode *head = malloc(sizeof(struct ListNode));

    for (int i = 0; i < size; ++i) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = rand();
        head->next = node;
    }

    return head;
}


void freeMem(struct ListNode* head)
{
    while (head->next != NULL)
    {
        head = head->next;
        free(head);
    }
}

int main(int argc, char *argv[])
{
    struct ListNode *l1 = generate(4);
    struct ListNode *l2 = generate(4);
    struct ListNode *temp = mergeTwoLists(l1, l2);
    freeMem(l1);
    freeMem(l2);
    freeMem(temp);
}