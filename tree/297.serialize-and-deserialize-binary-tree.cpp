#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    int getVal(string data, int size, int start, int& end) {
        int val = 0, neg = 0;
        if(start < size && data[start] == '-') {
            neg = 1;
            start++;
        }
        for(end=start; end<size && isdigit(data[end]); end++) 
            val = val * 10 + data[end] - '0';
        return neg ? -val : val;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string r = "";
        queue<TreeNode *> level;
        TreeNode *node;
        if(root == NULL)
            return r;

        level.push(root);
        r += to_string(root->val) + ",";

        while(!level.empty()) {
            int breadth = level.size();
            for(int i=0; i<breadth; i++) {
                node = level.front();
                level.pop();

                if(node->left) {
                    level.push(node->left);
                    r += to_string(node->left->val) + ",";
                } else {
                    r += ",";
                }
                if(node->right) {
                    level.push(node->right);
                    r += to_string(node->right->val) + ",";
                } else {
                    r += ",";
                }
            }
        }
        return r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return NULL;
        int size = data.size();
        int i, j, val;
        TreeNode *root, *parent;
        queue<TreeNode *> q;

        val = getVal(data, size, 0, j);
        root = new TreeNode(val);
        q.push(root);
        i = j+1;

        while(!q.empty()) {
            parent = q.front();
            q.pop();
            val = getVal(data, size, i, j);
            if(j != i) {
                parent->left = new TreeNode(val);
                q.push(parent->left);
            }
            i=j+1;

            val = getVal(data, size, i, j);
            if(j != i) {
                parent->right = new TreeNode(val);
                q.push(parent->right);
            }
            i=j+1;
        }

        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
