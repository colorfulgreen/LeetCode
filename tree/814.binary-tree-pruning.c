#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* pruneTree(struct TreeNode* root) {
    if(root == NULL)
        return root;
    if(root->left)
        root->left = pruneTree(root->left);
    if(root->right)
        root->right = pruneTree(root->right);
    if(root->left == NULL && root->right == NULL && root->val == 0) {
        free(root);
        root = NULL;
    }
    return root;
}


