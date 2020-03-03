#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX_SIZE 10000

void postorderHelper(struct TreeNode *root, int *vals, int *returnSize) {
    if(root == NULL)
        return;
    postorderHelper(root->left, vals, returnSize);
    postorderHelper(root->right, vals, returnSize);
    vals[(*returnSize)++] = root->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *vals = malloc(sizeof(int) * MAX_SIZE);
    postorderHelper(root, vals, returnSize);
    return vals;
}


