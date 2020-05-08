//
// Created by 11135 on 2020/4/25.
//

#include <stdio.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//递归法，合并到任意一棵树
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2)
{
    if (t1 == NULL)
        return t2;
    if (t2 == NULL)
        return t1;

    t1->val += t2->val;

    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
}
