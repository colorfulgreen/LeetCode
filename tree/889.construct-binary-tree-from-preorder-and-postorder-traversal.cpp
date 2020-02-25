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
    TreeNode *constructFromPrePostHelper(vector<int>& pre, vector<int>& post, int& preIndex, int& postIndex) {
        if(preIndex == pre.size())
            return NULL;
        struct TreeNode *node = new TreeNode(pre[preIndex++]);
        if(node->val != post[postIndex]) {
            node->left = constructFromPrePostHelper(pre, post, preIndex, postIndex);
        }
        if(node->val != post[postIndex]) {
            node->right = constructFromPrePostHelper(pre, post, preIndex, postIndex);
        }
        postIndex++; // NOTE
        return node;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int preIndex=0, postIndex=0;
        return constructFromPrePostHelper(pre, post, preIndex, postIndex);
    }
};

int main(void) {
    vector<int> pre = {1,2,4,5,3,6,7};
    vector<int> post = {4,5,2,6,7,3,1};
    TreeNode *root = Solution().constructFromPrePost(pre, post);
    return 0;
}
