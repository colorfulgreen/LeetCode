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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> stk;
        TreeNode *cur;
        if(root == nullptr)
            return preorder;

        stk.push(root);
        while(!stk.empty()) {
            cur = stk.top();
            stk.pop();
            preorder.push_back(cur->val);
            if(cur->right)
                stk.push(cur->right);
            if(cur->left)
                stk.push(cur->left);
        }

        return preorder;
    }
};
