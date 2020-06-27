//
// Created by 11135 on 2020/5/25.
//

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool hasPathSum(struct TreeNode* root, int sum) {

    if (root == NULL) return false;
    //从根递减节点的值
    sum -= root->val;

    if (root->left == NULL && root->right == NULL && sum == 0) return true;

    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
