//
// Created by 11135 on 2021/2/20.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> res;
    int base, count, max_count;
    void update(int x)
    {
        if (x == base)
        {
            count++;
        }
        else
        {
            base = x;
            count = 1;
        }
        if (count == max_count)
        {
            res.push_back(base);
        }
        if (count > max_count)
        {
            max_count = count;
            res = vector<int>{base};
        }


    }



    void dfs(TreeNode *root)
    {
        if (root == nullptr) return;

        dfs(root->left);
        update(root->val);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};
