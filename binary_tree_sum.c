//
// Created by 11135 on 2020/3/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int val;
}Node;


#define max(a, b) (a > b ? a : b)

int binary_tree_sum(Node *root, int value, int *result, int index)
{
    int temp = 0;

    if(root == NULL)
        return 0;

    temp += binary_tree_sum(root->left, value, result, index++);
    temp += binary_tree_sum(root->right, value, result, index++);

    temp += root->val;

    if (temp == value)
    {
        result[index] = 1;
    }

    return temp;
}

bool match_subtree_sum(Node *root, int value)
{
    int result[100] = {0};

    binary_tree_sum(root,  value, result, 0);

    for (int i = 0; i < 100; ++i) {
        if (result[i] == 1)
        {
            return true;
        }
    }
    return false;
}

void pre_order_traversal(Node *root)
{
    if (root)
    {
        printf("%d ", root->val);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}


void mid_order_traversal(Node *root)
{
    if (root)
    {
        mid_order_traversal(root->left);
        printf("%d ", root->val);
        mid_order_traversal(root->right);
    }
}


void after_order_traversal(Node *root)
{
    if (root)
    {
        after_order_traversal(root->left);
        after_order_traversal(root->right);
        printf("%d ", root->val);
    }
}


int binary_tree_depth(Node *root)
{
    int left = 0, right = 0;
    if (root == NULL)
    {
        return 0;
    }

    left = binary_tree_depth(root->left);
    if (left == -1)
    {
        return -1;
    }

    right = binary_tree_depth(root->right);
    if (right == -1)
    {
        return -1;
    }

    return abs(left - right) < 2 ? max(left, right) + 1 : -1;

}


bool binary_is_balance(Node *root)
{
    return binary_tree_depth(root) != -1;
}


Node *merge_tree(Node *root1, Node *root2)
{
    if (root1 == NULL)
        return root2;
    if (root2 == NULL)
        return root1;

    root1->val += root2->val;

    root1->left = merge_tree(root1->left, root2->left);
    root1->right = merge_tree(root1->right, root2->right);

    return root1;
}

int ans = INT_MIN;
int max_side(Node *root)
{
    if (root == NULL) return 0;
    int left = max(0, max_side(root->left));
    int right = max(0, max_side(root->right));
    ans = max(ans, left + right + root->val);
    return max(left, right) + root->val;
}


int main(int argc, char **argv) {
    Node *root = malloc(sizeof(Node));
    Node *left = malloc(sizeof(Node));
    Node *right = malloc(sizeof(Node));
    Node *left1 = malloc(sizeof(Node));
    Node *left2 = malloc(sizeof(Node));
    Node *right1 = malloc(sizeof(Node));
    Node *right2 = malloc(sizeof(Node));
    Node *right3 = malloc(sizeof(Node));



    root->val = 1;
    left->val = 2;
    right->val = 3;
    left1->val = 4;
    right1->val = 5;
    left2->val = 6;
    right2->val = 7;
    right3->val = 8;

    root->left = left;
    root->right = right;
    left->left = left1;
    left->right = right1;
    right->left = left2;
    right->right = right2;
    left2->right = right3;
    printf("%d\n", match_subtree_sum(root, 24));
    printf("%d\n", binary_is_balance(root));
    printf("%d\n", max_side(root));
//    pre_order_traversal(root);
//    printf("\n");
//    mid_order_traversal(root);
//    printf("\n");
//    after_order_traversal(root);
}