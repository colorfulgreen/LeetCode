#include <vector>
#include <string>
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
    int extractVal(string S, int size, int& pos, int& depth) {
        depth = 0;
        int val = 0;
        for(; pos < size && S[pos] == '-'; pos++)
            depth++;
        for(; pos < size && isdigit(S[pos]); pos++) 
            val = val * 10 + S[pos] - '0';
        return val;
    }

public:
    TreeNode* recoverFromPreorder(string S) {
        int size = S.size();
        if(size == 0)
            return NULL;

        int pos = 0, depth, preDepth, val;
        stack<TreeNode *> stk;
        TreeNode *parent, *root;

        val = extractVal(S, size, pos, depth);
        root = new TreeNode(val);
        parent = root;
        preDepth = 0;
        while(pos < size) {
            val = extractVal(S, size, pos, depth);
            if(depth > preDepth) {
                stk.push(parent);
                preDepth = depth;
                parent->left = new TreeNode(val);
                parent = parent->left;
            }
            else if(depth <= preDepth) {
                while(depth < preDepth) {
                    stk.pop();
                    preDepth--;
                }
                parent = stk.top(); // 相等 depth 的 parent 不能出栈, case: 1-5--9---1----4--5---3-6 
                parent->right = new TreeNode(val);
                cout << parent->val << "->right=" << val << endl;
                parent = parent->right;
            }
        }
        return root;
    }
};

class Solution2 {
public:
    TreeNode* recoverFromPreorder(string S) {
        int size = S.size(), pos = 0;
        if(size == 0)
            return NULL;

        int depth = 0, value;
        // 可以使用 vector 实现 stack，以支持下标访问
        vector<TreeNode *> stk;
        TreeNode *root, *node;
        while(pos < size) {
            value = 0;
            depth = 0;
            for(; pos < size && S[pos] == '-'; pos++)
                depth++;
            for(; pos < size && isdigit(S[pos]); pos++)
                value = value * 10 + S[pos] - '0';
            node = new TreeNode(value);
            while(stk.size() > depth)
                stk.pop_back();
            if(!stk.empty()) {
                if(!stk.back()->left) 
                    stk.back()->left = node;
                else 
                    stk.back()->right = node;
            }
            stk.push_back(node);
        }
        return stk[0];
    }
};

int main(void) {
    string S = "1-2--3--4-5--6--7";
    Solution2().recoverFromPreorder(S);
    return 0;
}
