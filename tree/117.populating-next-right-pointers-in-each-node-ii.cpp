#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> q;
        Node *pre, *node;
        if(root == NULL)
            return root;
        q.push(root);
        while(!q.empty()) {
            int breadth = q.size();
            pre = q.front();
            q.pop();

            if(pre->left != NULL)
                q.push(pre->left);
            if(pre->right != NULL)
                q.push(pre->right);


            for(int i=1; i<breadth; i++) {
                node = q.front();
                q.pop();
                pre->next = node;
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
                pre = node;
            }
        }
        return root;
    }
};
