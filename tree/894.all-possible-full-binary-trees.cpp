#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode *> roots;
        if(N == 0) 
            return roots;
        if(N == 1) {
            TreeNode *root = new TreeNode(0);
            roots.push_back(root);
            return roots;
        }
        for(int i = 1; i <= N-2; i += 2) {
            vector<TreeNode *> leftRoots = allPossibleFBT(i);
            vector<TreeNode *> rightRoots = allPossibleFBT(N-i-1);
            for(auto l: leftRoots) {
                for(auto r: rightRoots) {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    roots.push_back(root);
                }
            }
        }
        return roots;
    }
};
