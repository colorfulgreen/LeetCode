#include <vector>
#include <map>
#include <queue>
using namespace std;

#define RED 0
#define BLUE 1

class Solution {
private:
    vector< vector< pair<int, int> > > initGraph(int n, vector< vector<int> >& red_edges, vector< vector<int> >& blue_edges) {
        vector< vector< pair<int, int> > > G;
        vector< vector<int> >::iterator e;

        G.resize(n);
        for(e=red_edges.begin(); e != red_edges.end(); e++) 
            G[(*e)[0]].push_back(make_pair((*e)[1], RED));
        for(e=blue_edges.begin(); e != blue_edges.end(); e++) 
            G[(*e)[0]].push_back(make_pair((*e)[1], BLUE));
        return G;
    }


public:
    vector<int> shortestAlternatingPaths(int n, vector< vector<int> >& red_edges, vector< vector<int> >& blue_edges) {
        vector< vector<int> > cost(n, vector<int>(2, -1));
        vector< vector< pair<int, int> > > G = initGraph(n, red_edges, blue_edges);
        queue< pair<int, int> > q;  // index, color
        pair<int, int> v1, v2;
        int i;
        vector<int> dis;

        // BFS
        q.push(make_pair(0, RED));
        q.push(make_pair(0, BLUE));
        cost[0][RED] = 0;
        cost[0][BLUE] = 0;
        while(!q.empty()) {
            v1 = q.front(); q.pop();
            for(i=0; i<G[v1.first].size(); i++) {
                v2 = G[v1.first][i];
                if(cost[v2.first][v2.second] != -1 || v1.second == v2.second)
                    continue;
                cost[v2.first][v2.second] = 1 + cost[v1.first][v1.second];
                q.push(make_pair(v2.first, v2.second));
            }
            
        }

        for(i=0; i<cost.size(); i++) {
            sort(cost[i].begin(), cost[i].end());
            dis.push_back(cost[i][0] == -1 ? cost[i][1] : cost[i][0]);
        }
        return dis;
        
    }
};
