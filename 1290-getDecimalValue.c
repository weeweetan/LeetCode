//
// Created by 11135 on 2020/1/24.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};


int getDecimalValue(struct ListNode* head)
{
    int sum = 0;
    struct ListNode *node = head;
    while (node != NULL)
    {
        sum = (sum << 1) + node->val;
        node = node->next;
    }

    return sum;
}


int main(int argc, char **argv)
{
    struct ListNode *list = NULL, *node = NULL, *current = NULL;
    for (int i = 0; i < 10; ++i) {
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = i % 2;
        if (list == NULL)
        {
            list = node;
            list->next = NULL;
        } else {
            current = list;
            while (current != NULL)
            {
                if (current->next == NULL)
                {
                    node->next = current->next;
                    current->next = node;
                    break;
                }

                current = current->next;

            }
        }
    }

    printf("%d\n", getDecimalValue(list));
}