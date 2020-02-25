#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstFromPreorderHelper(int *preorder, int preorderSize, int *index, int upper) {
    if(*index == preorderSize || preorder[*index] > upper)
        return NULL;
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = preorder[(*index)++];
    node->left = bstFromPreorderHelper(preorder, preorderSize, index, node->val); 
    node->right = bstFromPreorderHelper(preorder, preorderSize, index, upper);
    return node;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    int index = 0;
    return bstFromPreorderHelper(preorder, preorderSize, &index, INT_MAX);
}

int main(void) {
    int preorder[] = {8,5,1,7,10,12};
    int preorderSize = sizeof(preorder) / sizeof(int);
    struct TreeNode *root = bstFromPreorder(preorder, preorderSize);
    return 0;
}
