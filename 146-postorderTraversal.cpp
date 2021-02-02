//
// Created by 11135 on 2021/1/26.
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> stack1;
        stack<TreeNode *> stack2;
        vector<int> res;
        if (root == nullptr)
            return res;

        while (root != nullptr || !stack1.empty())
        {
            while (root != nullptr)
            {
                stack1.push(root);
                stack2.push(root);
                root = root->right;
            }

            if (!stack1.empty())
            {
                root = stack1.top();
                stack1.pop();
                root = root->left;
            }
        }

        while (!stack2.empty())
        {
            root = stack2.top();
            res.push_back(root->val);
        }

        return res;
    }
};
