#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX_SIZE 10000
struct TreeNode *insert(struct TreeNode *root1, int val) {
    if(root1 == NULL) {
        root1 = malloc(sizeof(struct TreeNode));
        root1->val = val;
        root1->left = NULL;
        root1->right = NULL;
    }
    else if(val < root1->val) 
        root1->left = insert(root1->left, val);
    else if(val >= root1->val) 
        root1->right = insert(root1->right, val);
    return root1;
}

struct TreeNode *mergeTree(struct TreeNode* root1, struct TreeNode* root2) {
    if(root2->left != NULL)
        mergeTree(root1, root2->left);
    root1 = insert(root1, root2->val);
    if(root2->right != NULL)
        mergeTree(root1, root2->right);
    return root1;
}

void inorder(struct TreeNode *root, int *elements, int *returnSize) {
    if(root == NULL)
        return;
    inorder(root->left, elements, returnSize);
    elements[(*returnSize)++] = root->val;
    inorder(root->right, elements, returnSize);
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    *returnSize = 0;
    if(root1 == NULL && root2 == NULL)
        return NULL;

    if(root1 != NULL && root2 != NULL)
        root1 = mergeTree(root1, root2);
    else if(root1 == NULL)
        root1 = root2;

    int *elements = malloc(sizeof(int) * MAX_SIZE);
    inorder(root1, elements, returnSize);
    return elements;

}


