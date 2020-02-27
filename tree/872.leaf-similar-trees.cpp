#include <vector>
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
    void fetchLeaves(TreeNode *root, vector<int> &leaves) {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL) 
            leaves.push_back(root->val);
        else {
            if(root->left)
                fetchLeaves(root->left, leaves);
            if(root->right)
                fetchLeaves(root->right, leaves);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        fetchLeaves(root1, leaves1);
        fetchLeaves(root2, leaves2);
        if(leaves1.size() != leaves2.size())
            return false;
        for(int i=0; i<leaves1.size(); i++) 
            if(leaves1[i] != leaves2[i])
                return false;
        return true;
    }
};


int main(void) {
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    bool similar = Solution().leafSimilar(root1, root2);
    cout << similar << endl;
    return 0;
}
