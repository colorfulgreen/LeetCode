#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val){
    if(root == NULL) {
        root = malloc(sizeof(struct TreeNode));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if(val > root->val) {
        struct TreeNode *node = malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = root;
        node->right = NULL;
        return node;
    }
    root->right = insertIntoMaxTree(root->right, val);

    return root;
}


