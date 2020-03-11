#include <map>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {

private:
    void removeLeaf(map<int, set<int> >& T, int N, int leaf) {
        for(set<int>::iterator adj=T[leaf].begin(); adj!=T[leaf].end(); adj++) {
            T[*adj].erase(leaf);
            if(T[*adj].size() == 1)
                removeLeaf(T, N, *adj);
        }
        T.erase(leaf);
        cout << "erase " << leaf << endl;
    }

public:
    vector<int> findRedundantConnection(vector< vector<int> >& edges) {
        map<int, set<int> > T;
        int i, N;

        // build table
        for(i=0; i<edges.size(); i++) {
            T[edges[i][0]].insert(edges[i][1]);
            T[edges[i][1]].insert(edges[i][0]);
        }
        N = T.size();

        // remove leafs
        for(i=1; i<=N; i++) {
            if(T.find(i) != T.end() && T[i].size() == 1)  // TODO map 
                removeLeaf(T, N, i);
        }

        // find redundant
        for(i=edges.size()-1; i>=0; i--) {
            if(T.find(edges[i][0]) != T.end() && T.find(edges[i][1]) != T.end()) 
                return edges[i];
        }
        return edges[0];
    }
};

int main(void) {
    vector< vector<int> > edges;
    vector<int> edge;
    int data[][2] = {{16,25},{7,9},{3,24},{10,20},{15,24},{2,8},{19,21},{2,15},{13,20},{5,21},{7,11},{6,23},{7,16},{1,8},{17,20},{4,19},{11,22},{5,11},{1,16},{14,20},{1,4},{22,23},{12,20},{15,18},{12,16}};
    int i;
    for(i=0; i<25; i++) {
        edge.clear();
        edge.push_back(data[i][0]);
        edge.push_back(data[i][1]);
        edges.push_back(edge);
    }
    edge = Solution().findRedundantConnection(edges);
    for(i=0; i<2; i++)
        cout << edge[i] << endl;
    return 0;
}
