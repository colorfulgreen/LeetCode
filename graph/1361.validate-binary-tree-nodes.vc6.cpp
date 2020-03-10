#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int findRoot(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        int i;
        for(i=0; i<n; i++) {
            if(leftChild[i] != -1)
                indegree[leftChild[i]]++;
            if(rightChild[i] != -1)
                indegree[rightChild[i]]++;
        }
        for(i=0; i<n; i++)
            if(indegree[i] == 0)
                return i;
        return -1;
    }
    
    bool dfs(vector<int>& leftChild, vector<int>& rightChild, set<int>& nodes, int root) {
        bool valid;

        if(root == -1)
            return true;
        if(nodes.find(root) != nodes.end())
            return false;

        nodes.insert(root);
        valid = dfs(leftChild, rightChild, nodes, leftChild[root]);
        if(valid)
            valid = dfs(leftChild, rightChild, nodes, rightChild[root]);
        return valid;
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root;
        bool valid;
        set<int> nodes;

        root = findRoot(n, leftChild, rightChild);
        if(root == -1)
            return false;

        valid = dfs(leftChild, rightChild, nodes, root);
        if(valid && nodes.size() == n)
            return true;
        return false;

    }
};

int main(void) {
    int n = 4;
    static const int arr[] = {1,-1,3,-1};
    vector<int> leftChild(arr, arr+sizeof(arr)/sizeof(int));
    static const int arr2[] = {2,-1,-1,-1};
    vector<int> rightChild(arr2, arr2+sizeof(arr2)/sizeof(int));
    int valid = Solution().validateBinaryTreeNodes(n, leftChild, rightChild);
    cout << valid << endl;
    return 0;
}
