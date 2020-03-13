#include <vector>
#include <map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    Node *helper(Node *node, map<int, Node*>& dp) {
        vector<Node *> neighbors;

        if(node == NULL)
            return NULL;
        if(dp.find(node->val) != dp.end())
            return dp[node->val];

        dp[node->val] = new Node(node->val);     
        for(vector<Node *>::iterator i=node->neighbors.begin(); i!=node->neighbors.end(); i++) {
            dp[node->val]->neighbors.push_back(helper(*i, dp));
        }
        return dp[node->val];
    }

public:
    Node* cloneGraph(Node* node) {
        map<int, Node*> dp;
        return helper(node, dp);
    }
};
