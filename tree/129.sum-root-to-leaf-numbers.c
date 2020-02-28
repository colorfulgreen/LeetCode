#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void preorder(struct TreeNode *root, int cur, int* sum) {
    if(root == NULL)
        return;

    cur = cur * 10 + root->val;
    if(root->left == NULL && root->right == NULL) {
        *sum += cur;
        return;
    }

    if(root->left)
        preorder(root->left, cur, sum);
    if(root->right)
        preorder(root->right, cur, sum);
}

int sumNumbers(struct TreeNode* root){
    int sum, cur = 0;
    preorder(root, cur, &sum);
    return sum;
}


