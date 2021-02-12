//
// Created by 11135 on 2021/1/24.
//
#include <iostream>


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:

    void connectTwoNode(Node *node1, Node *node2)
    {
        if (node1 == NULL || node2 == NULL)
        {
            return;
        }

        node1->next = node2;

        connectTwoNode(node1->left, node1->right);
        connectTwoNode(node2->left, node2->right);

        connectTwoNode(node1->right, node2->left);
    }


    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        connectTwoNode(root->left, root->right);
        return root;
    }
};
