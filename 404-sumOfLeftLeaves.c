//
// Created by 11135 on 2020/4/23.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode* root)
{
    int sum = 0;
    if (root == NULL) return 0;

    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
    {
        sum += root->left->val;
    }

    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

typedef struct TreeNode Node;

int main(int argc, char **argv) {
    Node *root = malloc(sizeof(Node));
    Node *left = malloc(sizeof(Node));
    Node *right = malloc(sizeof(Node));
    Node *left1 = malloc(sizeof(Node));
    Node *left2 = malloc(sizeof(Node));
    Node *right1 = malloc(sizeof(Node));
    Node *right2 = malloc(sizeof(Node));
    Node *right3 = malloc(sizeof(Node));

    Node *root1 = malloc(sizeof(Node));

    root->val = 1;
    left->val = 2;
    right->val = 3;
    left1->val = 4;
    right1->val = 5;
    left2->val = 6;
    right2->val = 7;
    right3->val = 8;
    root1->val = 1;


    root->left = left;
    root->right = right;
    left->left = left1;
    left->right = right1;
    right->left = left2;
    right->right = right2;
//    left2->right = right3;

    root1->right = left;

    printf("%d\n", sumOfLeftLeaves(root));
}