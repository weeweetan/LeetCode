//
// Created by 11135 on 2021/2/8.
//
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    //深度优先，递归实现
    void dfs(Node *root, vector<int>& res)
    {
        if (!root) return;
        for (auto node : root->children)
        {
            dfs(node, res);
        }
        res.push_back(root->val);

    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        dfs(root, res);
        return res;
    }

    vector<int> postorderTraversal1(Node *root) {
        vector<int> ret;
        if (!root)
            return ret;

        stack <Node *> stack1;
        stack1.push(root);
        while (!stack1.empty())
        {
            Node *node = stack1.top();
            stack1.pop();

            if (node)
            {
                ret.insert(ret.begin(), node->val);
            }
            else
            {
                continue;
            }
            //遍历子树
            if (!node->children.empty())
            {
                int size = node->children.size();
                for (int i = 0 ; i < size; i++) {
                    Node *n = node->children[i];
                    if (n)
                        stack1.push(n);
                }
            }

        }
        return ret;
    }
};
