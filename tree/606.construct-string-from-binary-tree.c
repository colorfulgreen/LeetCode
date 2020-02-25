#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10000

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


char * tree2str(struct TreeNode* t){
    char *result = malloc(sizeof(char) * MAX_LEN * 2);
    result[0] = '\0';
    if(t == NULL)
        return result;
    char *leftStr, *rightStr;
    if(t->right != NULL) {
        leftStr = tree2str(t->left);
        rightStr = tree2str(t->right);
        snprintf(result, MAX_LEN, "%d(%s)(%s)", t->val, leftStr, rightStr);
        free(leftStr);
        free(rightStr);
    } else if(t->left != NULL) {
        leftStr = tree2str(t->left);
        snprintf(result, MAX_LEN, "%d(%s)", t->val, leftStr);
        free(leftStr);
    } else {
        snprintf(result, MAX_LEN, "%d", t->val);
    }
    return result;
}


