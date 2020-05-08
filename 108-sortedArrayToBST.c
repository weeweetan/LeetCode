//
// Created by 11135 on 2020/5/7.
//

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize <= 0) return NULL;

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    int left = 0, right = numsSize - 1, mid = left + (right - left)/2;

    root->val = nums[mid];
    root->left = sortedArrayToBST(nums, mid);
    root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);

    return root;
}

typedef struct TreeNode Node;

void pre_order_traversal(Node *root)
{
    if (root)
    {
        printf("%d ", root->val);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

int main(int argc, char **argv)
{
    int nums[] = {-10,-3,0,5,9};
    struct TreeNode *root = sortedArrayToBST(nums, 5);
    pre_order_traversal(root);
}