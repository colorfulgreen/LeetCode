#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

// https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C%2B%2BJavaPython-Pre-order-and-Post-order-DFS-O(N)

class Solution {
private:
    vector< set<int> > tree;
    vector<int> count, res;
    void postorderDFS(int root, int pre) {
        for(set<int>::iterator i=tree[root].begin(); i != tree[root].end(); i++) {
            if(*i == pre)
                continue;
            postorderDFS(*i, root);
            count[root] += count[*i];
            res[root] += count[*i] + res[*i];
        }
    }

    void preorderDFS(int root, int pre) {
        for(set<int>::iterator i=tree[root].begin(); i != tree[root].end(); i++) {
            if(*i == pre)
                continue;
            res[*i] = res[root] - count[*i] + count.size() - count[*i];
            preorderDFS(*i, root);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int N, vector< vector<int> >& edges) {
        tree.resize(N);
        count.assign(N, 1);
        res.assign(N, 0);

        for(int i=0; i<edges.size(); i++) {
			vector<int> edge = edges[i];
            tree[edge[0]].insert(edge[1]);
            tree[edge[1]].insert(edge[0]);
        }

        postorderDFS(0, -1);
        preorderDFS(0, -1);

        return res;
    }
};