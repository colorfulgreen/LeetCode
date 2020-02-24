#include <iostream>
#include <vector>
#include <stack>

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

class Solution {
private:
    void helper(Node *node, vector<int> &result) {
        if(node == nullptr)
            return;
        result.push_back(node->val);
        for(auto child: node->children) {
            helper(child, result);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
};


class Solution2 {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if(root == nullptr)
            return result;

        stack<Node *> stack;
        stack.push(root);
        while(!stack.empty()) {
            Node *node = stack.top();
            stack.pop();
            result.push_back(node->val);
            for(int i=node->children.size()-1; i>=0; i--) {
                stack.push(node->children[i]);
            }
        }
        return result;
    }
};


int main(void) {
    Node node5=Node(5), node6=Node(6), node2=Node(2), node4=Node(4);
    vector<Node *> children3 = {&node5, &node6};
    Node node3 = Node(3, children3);
    vector<Node *> children1 = {&node3, &node2, &node4};
    Node root = Node(1, children1);
    vector<int> preorder = Solution2().preorder(&root);
    for(int i: preorder) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
