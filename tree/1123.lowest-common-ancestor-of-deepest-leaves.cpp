#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *lcaHelper(TreeNode *root, int& deepest, int depth) {
        if(root == NULL)
            return NULL;

        int leftDeepest = depth, rightDeepest = depth;
        TreeNode *lcaLeft, *lcaRight, *lca;
        if(root->left)
            lcaLeft = lcaHelper(root->left, leftDeepest, depth+1);
        if(root->right)
            lcaRight = lcaHelper(root->right, rightDeepest, depth+1);

        if(leftDeepest < rightDeepest) {
            deepest = rightDeepest;
            return lcaRight;
        }
        if(leftDeepest > rightDeepest) {
            deepest = leftDeepest;
            return lcaLeft;
        }
        deepest = leftDeepest;
        return root;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = 0, deepest;
        TreeNode *lca = lcaHelper(root, deepest, depth);
        return lca;
    }
};
