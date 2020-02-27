#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool equalsSum(struct TreeNode *root, int sum, int cur) {
    cur += root->val;
    if(root->left == NULL && root->right == NULL)
        return cur == sum;

    if(root->left != NULL && equalsSum(root->left, sum, cur))
        return true;
    if(root->right != NULL && equalsSum(root->right, sum, cur))
        return true;
    return false;
}

bool hasPathSum(struct TreeNode* root, int sum){
    int cur = 0;
    if(root == NULL)
        return cur == sum;

    return equalsSum(root, sum, cur);
}


