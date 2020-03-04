#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void preorder(struct TreeNode *root, long int* sum) {
    if(root->left)
        preorder(root->left, sum);
    *sum += root->val;
    if(root->right)
        preorder(root->right, sum);
}

long int postorder(struct TreeNode *root, long int sum, long int *maxProduct) {
    if(root == NULL)
        return 0;

    int leftSum = 0, rightSum = 0;
    leftSum = postorder(root->left, sum, maxProduct);
    if(leftSum * (sum - leftSum) > *maxProduct)
        *maxProduct = leftSum * (sum - leftSum);
    rightSum = postorder(root->right, sum, maxProduct);
    if(rightSum * (sum - rightSum) > *maxProduct)
        *maxProduct = rightSum * (sum - rightSum);
    return leftSum + rightSum + root->val;
}

int maxProduct(struct TreeNode* root){
    long int sum = 0;
    long int maxProduct = 0;
    preorder(root, &sum);
    long int r = postorder(root, sum, &maxProduct);
    return maxProduct % (1000000007);
}
