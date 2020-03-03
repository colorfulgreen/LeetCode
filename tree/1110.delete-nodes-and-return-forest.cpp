#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* delNodesPostorder(TreeNode *root, vector<int>& to_delete, vector<TreeNode*>& forest, bool is_root) {
        if(root == NULL)
            return NULL;
        if(root->left) 
            root->left = delNodesPostorder(root->left, to_delete, forest, false);
        if(root->right)
            root->right = delNodesPostorder(root->right, to_delete, forest, false);
        for(int val: to_delete) {
            if(val == root->val) {
                if(root->left)
                    forest.push_back(root->left);
                if(root->right)
                    forest.push_back(root->right);
                return NULL;
            }
        }
        if(is_root)
            forest.push_back(root);
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        delNodesPostorder(root, to_delete, forest, true);
        return forest;
    }
};
