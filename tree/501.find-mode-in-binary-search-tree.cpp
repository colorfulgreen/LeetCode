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
    vector<int> modes;

    void getMaxFreq(TreeNode* r, int& maxFreq, int& preVal, int& cnt) {
        // 二叉搜索树中序遍历的结果是单调递增的。
        // 如果左子树有值和 root 相等，一定位于子树前序遍历的尾部（即子树的最右下方）。
        // 如果右子树有值和 root 相等，一定位于子树前序遍历的头部（即子树的最左下方）。
        if (!r) return;

        getMaxFreq(r->left, maxFreq, preVal, cnt);

        cnt = r->val == preVal ? cnt + 1 : 1;
        maxFreq = max(maxFreq, cnt);
        getMaxFreq(r->right, maxFreq, preVal=r->val, cnt);
    }
    
    void getMode(TreeNode* r, const int maxFreq, int& preVal, int& cnt) {
        if (!r) return;

        getMode(r->left, maxFreq, preVal, cnt);
        cnt = r->val == preVal ? cnt + 1 : 1;
        if(maxFreq == cnt)
            modes.push_back(r->val);

        getMode(r->right, maxFreq, preVal=r->val, cnt);
    }

public:
    vector<int> findMode(TreeNode* r) {
        int maxFreq, preVal, cnt;
        getMaxFreq(r, maxFreq=0, preVal=-1, cnt=0); // in-order traversal to get max frequency
        getMode(r, maxFreq, preVal, cnt=0);      // in-order traversal to get all modes
        return modes;
    }
};
