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
    TreeNode *bstFromPreorderHelper(vector<int>& preorder, int &index, int upper) {
        if(index == preorder.size() || preorder[index] > upper)
            return NULL;
        struct TreeNode *node = new TreeNode(preorder[index++]);
        node->left = bstFromPreorderHelper(preorder, index, node->val);
        node->right = bstFromPreorderHelper(preorder, index, upper);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return bstFromPreorderHelper(preorder, index, INT_MAX);
    }
};

int main(void) {
    vector<int> preorder = {8,5,1,7,10,12};
    TreeNode *root = Solution().bstFromPreorder(preorder);
    return 0;
}
