//
// Created by 11135 on 2020/4/27.
//

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int rangeSumBST(struct TreeNode* root, int L, int R) {
    int temp = 0;

    if (root == NULL) return 0;

    if (root->val >= L && root->val <= R)
    {
        temp += root->val;
    }

    if (L < root->val)
    {
        temp += rangeSumBST(root->left, L, R);
    }

    if (R > root->val)
    {
        temp += rangeSumBST(root->right, L, R);
    }

    return temp;

}

typedef struct TreeNode Node;

int main(int argc, char **argv)
{
    Node *root = malloc(sizeof(Node));
    Node *left = malloc(sizeof(Node));
    Node *right = malloc(sizeof(Node));
    Node *left1 = malloc(sizeof(Node));
    Node *left2 = malloc(sizeof(Node));
    Node *right1 = malloc(sizeof(Node));
    Node *right2 = malloc(sizeof(Node));
    Node *right3 = malloc(sizeof(Node));



    root->val = 1;
    left->val = 2;
    right->val = 3;
    left1->val = 4;
    right1->val = 5;
    left2->val = 6;
    right2->val = 7;
    right3->val = 8;

    root->left = left;
    root->right = right;
    left->left = left1;
    left->right = right1;
    right->left = left2;
    right->right = right2;
    left2->right = right3;

    printf("%d\n", rangeSumBST(root, 1, 7));
}