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
    void sumRootToLeafHelper(TreeNode *root, int cur, int& sum) {
        if(root == NULL)
            return;

        cur = (cur << 1) + root->val;
        cout << cur << " " << (cur << 1) << endl;
        if(root->left == NULL && root->right == NULL) {
            sum += cur;
        }
        else {
            if(root->left)
                sumRootToLeafHelper(root->left, cur, sum);
            if(root->right)
                sumRootToLeafHelper(root->right, cur, sum);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0, cur = 0;
        sumRootToLeafHelper(root, cur, sum);
        return sum;
    }
};
