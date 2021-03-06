//
// Created by 11135 on 2020/10/10.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        //根结点入队列
        queue <TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int currentLevelSize = q.size();
            ret.push_back(vector<int>());
            //遍历当前层
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                //左右结点入队列
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ret;
    }
};


int main(int argc, char **argv)
{
    
}
