#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        TreeNode *node;
        int maxSum = root->val, minLevel = 1;
        int breadth, i, sum, level = 1;

        q.push(root);
        while(!q.empty()) {
            sum = 0;
            breadth = q.size();
            for(i=0; i<breadth; i++) {
                node = q.front();
                q.pop();
                sum += node->val;
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
            if(sum > maxSum) {
                maxSum = sum;
                minLevel = level;
            }
            level++;
        }
        return minLevel;      
    }
};
