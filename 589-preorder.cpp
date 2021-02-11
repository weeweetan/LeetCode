//
// Created by 11135 on 2021/2/1.
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
    void dfs(Node *root, vector<int>& res)
    {
        if (!root) return;
        res.push_back(root->val);
        for (auto node : root->children)
        {
            dfs(node, res);
        }
    }


    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        dfs(root, res);
    }

    vector<int> preorderTraversal1(Node *root) {
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
                ret.push_back(node->val);
            }
            else
            {
                continue;
            }

            if (!node->children.empty())
            {
                int size = node->children.size();
                for (int i = size -1 ; i >= 0; i--) {
                    Node *n = node->children[i];
                    if (n)
                        stack1.push(n);
                }
            }

        }
        return ret;
    }

};
