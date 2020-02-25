#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string tree2str(TreeNode* t) {
        string s = "";
        if(t == nullptr) {
            return s;
        }
        s += to_string(t->val);
        if(t->right) {
            s += "(" + tree2str(t->left) + ")";
            s += "(" + tree2str(t->right) + ")";
        } else if(t->left) {
            s += "(" + tree2str(t->left) + ")";
        }
        return s;
    }
};
