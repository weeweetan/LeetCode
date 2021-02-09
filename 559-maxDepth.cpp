//
// Created by 11135 on 2021/2/8.
//
#include <iostream>
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
    int maxDepth(Node* root) {
        int max = INT32_MIN;

        if (root == nullptr) return 0;
        else if (root->children.empty()) return 1;
        else
        {
            int temp;
            for (auto child : root->children) {
                temp = maxDepth(child);
                if (temp > max)
                    max = temp;

            }

            return max + 1;
        }
    }
};
