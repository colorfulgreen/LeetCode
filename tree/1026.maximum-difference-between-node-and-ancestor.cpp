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
    void preorder(TreeNode *root, vector<int>& ancestors, int& maxDiff) {
        for(auto val: ancestors) {
            if(abs(root->val - val) > maxDiff)
                maxDiff = abs(root->val - val);
        }
        ancestors.push_back(root->val);
        if(root->left)
            preorder(root->left, ancestors, maxDiff);
        if(root->right)
            preorder(root->right, ancestors, maxDiff);
        ancestors.pop_back();

    }
public:
    int maxAncestorDiff(TreeNode* root) {
        vector<int> ancestors;
        int maxDiff = 0;
        preorder(root, ancestors, maxDiff);
        return maxDiff;
    }
};
