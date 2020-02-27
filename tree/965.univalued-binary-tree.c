#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isUnivalTree(struct TreeNode* root){
    if(root == NULL)
        return true;
    if(root->left != NULL && !(root->left->val == root->val && isUnivalTree(root->left)))
        return false;
    if(root->right != NULL && !(root->right->val == root->val && isUnivalTree(root->right)))
        return false;
    return true;
}


