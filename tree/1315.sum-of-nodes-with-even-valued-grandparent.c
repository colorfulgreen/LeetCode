#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void sumEvenGrandparentHelper(struct TreeNode *root, int *sum, int mask) {
    if(root == NULL)
        return;

    if(mask & 1)
        *sum += root->val;

    mask >>= 1;
    if(root->val % 2 == 0)
        mask |= 2;
    sumEvenGrandparentHelper(root->left, sum, mask);
    sumEvenGrandparentHelper(root->right, sum, mask);
}

int sumEvenGrandparent(struct TreeNode* root){
    int sum = 0;
    int mask = 0;
    sumEvenGrandparentHelper(root, &sum, mask);
    return sum;
}


