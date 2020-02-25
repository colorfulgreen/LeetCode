#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode *buildTreeHelper(int* preorder, int preorderSize, int* inorder, int inorderSize, 
                                 int* preIndex, int* inIndex, int inVal) {
    if(*preIndex == inorderSize)
        return NULL;
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = preorder[(*preIndex)++];
    if(node->val != inorder[*inIndex]) {
        node->left = buildTreeHelper(preorder, preorderSize, inorder, inorderSize, preIndex, inIndex, node->val); 
    } else {
        node->left = NULL;
    }
    (*inIndex)++;
    if(*inIndex < inorderSize && inVal != inorder[*inIndex]) {
        node->right = buildTreeHelper(preorder, preorderSize, inorder, inorderSize, preIndex, inIndex, inVal); 
    } else {
        node->right = NULL;
    }
    return node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    int preIndex = 0, inIndex = 0;
    return buildTreeHelper(preorder, preorderSize, inorder, inorderSize, &preIndex, &inIndex, -1);
}


