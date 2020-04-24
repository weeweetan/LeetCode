//
// Created by 11135 on 2020/4/22.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool Symmetric(struct TreeNode* leftNode, struct TreeNode* rightNode)
{
    if (NULL == leftNode && NULL == rightNode)
    {
        return true;
    }

    if (NULL == leftNode || NULL == rightNode)
    {
        return false;
    }

    return (leftNode->val == rightNode->val) &&           \
            Symmetric(leftNode->right, rightNode->left) && \
            Symmetric(leftNode->left, rightNode->right);
}

bool isSymmetric(struct TreeNode* root)
{
    return Symmetric(root, root);
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

    root->left = left;
    root->right = right;

    printf("%d\n", isSymmetric(root));

}