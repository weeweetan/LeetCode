//
// Created by 11135 on 2020/5/13.
//

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//返回左右子树最大深度
int minDepth(struct TreeNode* root) {

    int left, right;
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    if (root->left != NULL && root->right == NULL) {
        return minDepth(root->left) + 1;
    }

    if (root->right != NULL && root->left == NULL) {
        return minDepth(root->right) + 1;
    }

    left = minDepth(root -> left);
    right = minDepth(root -> right);
    return left > right ? right + 1 : left + 1;
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

    printf("%d\n", minDepth(root));
}
