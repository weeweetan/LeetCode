//
// Created by 11135 on 2020/4/30.
//

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//返回左右子树最大深度,使用递归完成
int maxDepth(struct TreeNode* root) {

    int left, right;
    if (root == NULL)
        return 0;
    
    left = maxDepth(root->left);

    right = maxDepth(root->right);
    //返回比较大的子树深度+1
    return left > right ? left + 1 : right + 1;
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

    printf("%d\n", maxDepth(root));
}
