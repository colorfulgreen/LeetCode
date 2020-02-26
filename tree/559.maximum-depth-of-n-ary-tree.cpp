#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


// DFS
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        int depth = 0;
        for(auto child: root->children) {
            depth = max(depth, maxDepth(child));
        }
        return depth + 1;
    }
};


// BFS
class Solution2 {
public:
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;

        int depth = 0, breadth;
        Node *node;
        queue<Node *> q;

        q.push(root);
        while(!q.empty()) {
            depth++;
            breadth = q.size();
            for(; breadth > 0; breadth--) {
                node = q.front();
                q.pop();
                for(auto child: node->children)
                    if(child)
                        q.push(child);
            }
        }
        return depth;
    }
};
