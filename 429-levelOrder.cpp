//
// Created by 11135 on 2021/1/30.
//
#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> q;
        vector<vector<int>> ret;

        if (root == nullptr)
            return ret;

        q.push(root);
        while (!q.empty())
        {
            vector<int> v;
            size_t size = q.size();
            for (int i = 0; i < size; i++) {
                Node *node = q.front();
                q.pop();
                v.push_back(node->val);
                for (auto child : node->children)
                {
                    if (child != nullptr) q.push(child);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};
