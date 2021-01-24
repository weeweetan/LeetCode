//
// Created by 11135 on 2021/1/24.
//
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;

        queue <TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int currentLevelSize = q.size();
            vector<int> v;
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                v.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ret.insert(ret.begin(), v);
        }
        return ret;
    }
};
