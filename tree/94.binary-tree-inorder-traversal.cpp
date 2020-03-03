#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void inorder(TreeNode* root, vector<int>& vals) {
        if(root == NULL)
            return;
        if(root->left)
            inorder(root->left, vals);
        vals.push_back(root->val);
        if(root->right)
            inorder(root->right, vals);
        
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        return vals;
    }
};

// iterate
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        stack<TreeNode *> todo;
        while(root || !todo.empty()) {
            while(root) {
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            todo.pop();
            vals.push_back(root->val);
            root = root->right;
        }
        return vals;
    }

};
