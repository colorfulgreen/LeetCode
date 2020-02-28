#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int postorder(struct TreeNode *root, int *move) {
    if(root == NULL)
        return 0;

    int excess = 0;
    if(root->left) 
        excess += postorder(root->left, move);
    if(root->right)
        excess += postorder(root->right, move);
    excess += root->val - 1;
    if(excess != 0)
        *move += excess > 0 ? excess : -excess;
    return excess;
}


int distributeCoins(struct TreeNode* root){
    int move = 0, excess;
    excess = postorder(root, &move);
    return move;
}


