//
// Created by 11135 on 2020/3/3.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//交换左右子树
struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    struct TreeNode *left = invertTree(root->left);
    struct TreeNode *right = invertTree(root->right);

    root->right = left;
    root->left = right;

}

int main(int argc, char **argv)
{
    
}
