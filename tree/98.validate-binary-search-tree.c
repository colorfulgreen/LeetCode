#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool preorder(struct TreeNode* root, int* largest) {
    bool valid = true;
    if(root->left)
        valid = preorder(root->left, largest);
    if(*largest >= root->val)
        valid = false;
    *largest = root->val;
    if(valid && root->right)
        valid = preorder(root->right, largest);
    return valid;
}

bool isValidBST(struct TreeNode* root){
    if(root == NULL)
        return true;
    int largest = -INT_MAX;
    bool r = preorder(root, &largest);
    return r;
}
