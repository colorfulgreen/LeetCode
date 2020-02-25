#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode *constructFromPrePostHelper(int *pre, int preSize, int *post, int postSize, int *preIndex, int *postIndex) {
    if(*preIndex == preSize)
        return NULL;
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = pre[(*preIndex)++];
    if(node->val != post[*postIndex]) {
        node->left = constructFromPrePostHelper(pre, preSize, post, postSize, preIndex, postIndex);
    } else {
        node->left = NULL;
    }
    if(node->val != post[*postIndex]) {
        node->right = constructFromPrePostHelper(pre, preSize, post, postSize, preIndex, postIndex);
    } else {
        node->right = NULL;
    }
    (*postIndex)++;
    return node;
}

struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize){
    int preIndex = 0, postIndex = 0;
    return constructFromPrePostHelper(pre, preSize, post, postSize, &preIndex, &postIndex);
}

int main(void) {
    int pre[] = {1,2,4,5,3,6,7}, post[] = {4,5,2,6,7,3,1};
    int preSize = sizeof(pre) / sizeof(int);
    int postSize = sizeof(post) / sizeof(int);
    constructFromPrePost(pre, preSize, post, postSize);
    return 0;
}



