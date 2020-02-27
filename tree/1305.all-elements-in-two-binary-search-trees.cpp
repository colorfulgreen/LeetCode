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
private:
    void pushLeft(TreeNode *root, stack<TreeNode *> &s) { // 注意 stack 要使用地址引用
        while(root != NULL) {
            s.push(root);
            root = root->left;
        }
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> elements;
        stack<TreeNode *> s1, s2;
        TreeNode *node;

        pushLeft(root1, s1);
        pushLeft(root2, s2);
        while(!s1.empty() || !s2.empty()) {
            // &s 必须在定义的同时初始化
            stack<TreeNode *> &s = s1.empty() ? s2 : s2.empty() ? s1 : 
                s1.top()->val < s2.top()->val ? s1 : s2;
            node = s.top();
            elements.push_back(node->val);
            s.pop();
            pushLeft(node->right, s);
        }
        return elements;
    }
};
