#include <stdlib.h>
#define MAX_LEN 1000

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode **stack;
int sp = 0;

void push(struct TreeNode *node) {
    stack[sp++] = node;
}

struct TreeNode *pop(void) {
    return stack[--sp];
}

int isEmpty(void) {
    return sp == 0 ? 1 : 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if(root == NULL)
        return NULL;

    int *preorder = malloc(sizeof(int) * MAX_LEN);
    struct TreeNode *curNode;
    stack = malloc(sizeof(struct TreeNode *) * MAX_LEN);
    sp = 0;

    push(root);
    while(!isEmpty()) {
        curNode = pop();
        preorder[(*returnSize)++] = curNode->val; 
        if(curNode->right != NULL) 
            push(curNode->right);
        if(curNode->left != NULL)
            push(curNode->left);
    }
    free(stack);
    return preorder;
}


