//
// Created by 11135 on 2021/1/9.
//
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void dfs(TreeNode *root, vector<int>& res)
    {
        if (!root) return;
        res.push_back(root->val);
        if (root->left) dfs(root->left, res);
        if (root->right) dfs(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }

    vector<int> preorderTraversal1(TreeNode *root) {
        vector<int> ret;
        if (!root)
            return ret;

        stack <TreeNode *> stack1;
        while (root != nullptr || !stack1.empty())
        {
            while (root != nullptr)
            {
                ret.push_back(root->val);
                stack1.push(root);
                root = root->left;
            }
            root = stack1.top();
            stack1.pop();
            root = root->right;
        }
        return ret;
    }

};