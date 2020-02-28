#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


typedef struct {
    int elements[10000];
    int size;
} FindElements;

void findElementsCreateHelper(struct TreeNode* root, FindElements *obj) {
    obj->elements[(obj->size)++] = root->val;

    if(root->left) {
        root->left->val = root->val * 2 + 1;
        findElementsCreateHelper(root->left, obj);
    }
    if(root->right) {
        root->right->val = root->val * 2 + 2;
        findElementsCreateHelper(root->right, obj);
    }
}

FindElements* findElementsCreate(struct TreeNode* root) {
    if(root == NULL)
        return NULL;
    FindElements *obj = malloc(sizeof(FindElements));
    obj->size = 0;

    root->val = 0;
    findElementsCreateHelper(root, obj);

    return obj;
}

bool findElementsFind(FindElements* obj, int target) {
    for(int i=0; i<obj->size; i++)
        if(obj->elements[i] == target)
            return true;
    return false;
}

void findElementsFree(FindElements* obj) {
    free(obj);
}

/**
 * Your FindElements struct will be instantiated and called as such:
 * FindElements* obj = findElementsCreate(root);
 * bool param_1 = findElementsFind(obj, target);
 
 * findElementsFree(obj);
*/
