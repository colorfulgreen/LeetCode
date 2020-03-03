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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vals;
        stack<TreeNode *> todo;
        TreeNode *last = NULL, *node;
        while(root || !todo.empty()) {
            if(root) {
                todo.push(root);
                root = root->left;
            }
            else {
                node = todo.top();
                if(node->right && last != node->right) {
                    root = node->right;
                }
                else {
                    vals.push_back(node->val);
                    last = node;
                    todo.pop();
                }
            }
        }
        return vals;
    }
};
