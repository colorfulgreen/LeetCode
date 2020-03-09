#include <iostream>
#include <set>
#include <queue>
using namespace std;

class Solution {
private:
    vector<pair<int, int>> genNeighbors(pair<int, int> pos) {
        vector<pair<int, int>> neighbors = {make_pair(pos.first-1, pos.second), 
                                            make_pair(pos.first+1, pos.second), 
                                            make_pair(pos.first, pos.second-1), 
                                            make_pair(pos.first, pos.second+1)};
        return neighbors;
    }

    void markIsland(vector<vector<int>> A, pair<int, int> pos, queue<pair<int, int>>& bfs) {
        bfs.push(pos);
        A[pos.first][pos.second] = -1;
        vector<pair<int, int>> neighbors = genNeighbors(pos);
        for(auto n: neighbors) { 
            if(n.first >= 0 && n.first < A.size() && n.second >=0 && n.second < A.size() && A[n.first][n.second] == 1) 
                markIsland(A, n, bfs);
        }
    }

public:
    int shortestBridge(vector<vector<int>>& A) {
        queue<pair<int, int>> bfs;
        pair<int, int> pos;
        vector<pair<int, int>> neighbors;
        int breadth = 0, depth = 0, i, j;

        for(i=0; i<A.size(); i++) {
            for(j=0; j<A.size(); j++) {
                if(A[i][j] == 1) {
                    markIsland(A, make_pair(i,j), bfs);
                    break;
                }
            }
            if(j!=A.size())
                break;
        }

        while(!bfs.empty()) {
            breadth = bfs.size();
            for(i=0; i<breadth; i++) {
                pos = bfs.front();
                bfs.pop();

                neighbors = genNeighbors(pos); 
                for(auto n: neighbors) {
                    if(n.first >= 0 && n.first < A.size() && n.second >=0 && n.second < A.size()) {
                        if(A[n.first][n.second] == 1) {
                            return depth;
                        }
                        else if(A[n.first][n.second] == 0) {
                            bfs.push(n);
                            A[n.first][n.second] = -1;
                        }
                    } 
                }
            }
            depth++;
        }

        return depth;
    }
};
