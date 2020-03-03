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
    void inorder(TreeNode* root, int depth, int& val, int& maxDepth) {
        if(root->left)
            inorder(root->left, depth+1, val, maxDepth);
        if(depth > maxDepth) {
            maxDepth = depth;
            val = root->val;
        }
        if(root->right)
            inorder(root->right, depth+1, val, maxDepth);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int depth = 0, maxDepth = 0;
        int val = root->val;
        inorder(root, depth, val, maxDepth);
        return val;
    }
};
