#include <stdlib.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int getMaxDepth(struct TreeNode* root) {
    int leftDepth = 0, rightDepth = 0;
    if(root->left != NULL)
        leftDepth = getMaxDepth(root->left);
    if(root->right != NULL)
        rightDepth = getMaxDepth(root->right);
    return MAX(leftDepth, rightDepth) + 1;
}

void getDeepestSum(struct TreeNode *root, int depth, int maxDepth, int *sum) {
    depth++;
    if(depth == maxDepth) { 
        *sum += root->val;
        return;
    }
    if(root->left != NULL)
        getDeepestSum(root->left, depth, maxDepth, sum);
    if(root->right != NULL)
        getDeepestSum(root->right, depth, maxDepth, sum);

}

int deepestLeavesSum(struct TreeNode* root) {
    if(root == NULL)
        return 0;

    int maxDepth = getMaxDepth(root);
    int depth = 0;
    int sum = 0;
    getDeepestSum(root, depth, maxDepth, &sum);
    return sum;
}


