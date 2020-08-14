//
// Created by 11135 on 2020/4/25.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numChildren;
    struct Node **children;
};
int array[100] = {0};
int index = 0;

void post_order(struct Node* root)
{
    if (root == NULL) return;
    
    for (int i = 0; i < root->numChildren; ++i) {
        post_order(root->children[i]);
    }

    array[index++] = root->val;
    printf("%d ", root->val);
}


int* postorder(struct Node* root, int* returnSize)
{
    int *list = malloc(sizeof(int) * (*returnSize));
    post_order(root);
    printf("\n");
    for (int i = 0; i < 6; ++i) {
        printf("%d ", array[i]);
    }
 //   return list;
}

typedef struct Node Node;


int main(int argc, char **argv)
{
    Node *root = malloc(sizeof(Node));
    Node *left = malloc(sizeof(Node));
    Node *mid = malloc(sizeof(Node));
    Node *right = malloc(sizeof(Node));
    Node *left1 = malloc(sizeof(Node));
    Node *left2 = malloc(sizeof(Node));
    Node *right1 = malloc(sizeof(Node));
    Node *right2 = malloc(sizeof(Node));
    Node *right3 = malloc(sizeof(Node));

//    Node *root1 = malloc(sizeof(Node));

    root->val = 1;
    left->val = 3;
    mid->val = 2;
    right->val = 4;
    left1->val = 5;
    right1->val = 6;
    left2->val = 6;
    right2->val = 7;
    right3->val = 8;
//    root1->val = 1;

    left->numChildren = 2;
    left->children = malloc(sizeof(Node) * 2);
    left->children[0] = left1;
    left->children[1] = right1;

    root->numChildren = 3;
    root->children = malloc(sizeof(Node) * 3);
    root->children[0] = left;
    root->children[1] = mid;
    root->children[2] = right;



//    root->right = right;
//    left->left = left1;
//    left->right = right1;
//    right->left = left2;
//    right->right = right2;
//    left2->right = right3;

    int returnSize = 6;
    postorder(root, &returnSize);
}