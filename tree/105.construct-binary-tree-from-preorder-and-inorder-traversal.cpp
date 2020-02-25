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
    TreeNode *buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int &preIndex, int &inIndex, int inVal) {
        if(preIndex == preorder.size())
            return NULL;
        struct TreeNode *node = new TreeNode(preorder[preIndex++]);
        if(node->val != inorder[inIndex]) {
            node->left = buildTreeHelper(preorder, inorder, preIndex, inIndex, node->val);
        }
        inIndex++;
        if(inIndex < inorder.size() && inVal != inorder[inIndex]) {
            node->right = buildTreeHelper(preorder, inorder, preIndex, inIndex, inVal);
        }
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0, inIndex = 0;
        return buildTreeHelper(preorder, inorder, preIndex, inIndex, -1);
    }
};


int main(void) {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> postorder = {9,3,15,20,7};
    Solution().buildTree(preorder, postorder);
    return 0;
}
