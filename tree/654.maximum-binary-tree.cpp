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
    TreeNode* insert(TreeNode *root, int num) {
        if(root == NULL) {
            root = new TreeNode(num);
        } 
        else if(num < root->val)  {
            root->right = insert(root->right, num);
        } 
        else if(num > root->val) {
            TreeNode *node = new TreeNode(num);
            node->left = root;
            root = node;
        }
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *root = NULL;
        for(int num: nums) {
            root = insert(root, num);
        }
        return root;
    }
};
