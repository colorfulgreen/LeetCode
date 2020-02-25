#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode **stack;
int sp;

void push(struct TreeNode *node) {
    stack[sp++] = node;
}

struct TreeNode *pop(void) {
    return stack[--sp];
}

int empty(void) {
    return sp == 0 ? 1 : 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* flipMatchVoyage(struct TreeNode* root, int* voyage, int voyageSize, int* returnSize){
    int* flip = malloc(sizeof(int) * voyageSize);
    struct TreeNode *cur, *tmp;
    int index = 0;
    *returnSize = 0;
    if(voyageSize == 0)
        return flip;

    stack = malloc(sizeof(struct TreeNode*) * voyageSize);
    sp = 0;
    push(root);
    while(!empty()) {
        cur = pop();
        if(cur->val != voyage[index++]) {
            flip[0] = -1;
            *returnSize = 1;
            return flip;
        }
        if(cur->left && cur->left->val != voyage[index]) {
            tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            flip[(*returnSize)++] = cur->val;
        }
        if(cur->right)
            push(cur->right);
        if(cur->left)
            push(cur->left);
    }
    return flip;
}


