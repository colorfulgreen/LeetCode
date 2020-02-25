#include <vector>
#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> failed = {-1};
        vector<int> flipNodes = {};
        stack<TreeNode *> stk;
        TreeNode *cur, *tmp;
        int index = 0;

        if(root == nullptr)
            return flipNodes;

        stk.push(root);
        while(!stk.empty()) {
            cur = stk.top();
            stk.pop();
            cout << cur->val << ", " << voyage[index] << endl;
            if(cur->val != voyage[index++]) 
                return failed;
            if(cur->left && cur->left->val != voyage[index]) {
                tmp = cur->left;
                cur->left = cur->right;
                cur->right = tmp;
                flipNodes.push_back(cur->val);
            }
            if(cur->right) 
                stk.push(cur->right);
            if(cur->left) 
                stk.push(cur->left);
        }
        return flipNodes;
    }
};

int main(void) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<int> voyage = {1,2,3};
    vector<int> ret = Solution().flipMatchVoyage(root, voyage);
    for(auto i: ret)
        cout << i << " ";
    cout << endl;
    return 0;
}
