#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector< vector<int> >& edges) {
        vector< set<int> > G;
        vector<int> cur, next;
        int i;

        if(n == 1) {
            cur.push_back(0);
            return cur;
        }

        // init graph
        G.resize(n);
        for(i=0; i<edges.size(); i++) {
            G[edges[i][0]].insert(edges[i][1]);
            G[edges[i][1]].insert(edges[i][0]);
        }

        // find leafs
        for(i=0; i<n; i++) {
            if(G[i].size() == 1)
                next.push_back(i);
        }

        // BFS
        while(!next.empty()) {
            cur = next;
            next.clear();
            for(vector<int>::iterator node=cur.begin(); node!=cur.end(); node++) {
                for(set<int>::iterator adj=G[*node].begin(); adj!=G[*node].end(); adj++) {
                    G[*adj].erase(*node);
                    if(G[*adj].size() == 1)
                        next.push_back(*adj);
                }
            }
        }

        return cur;

    }
};
