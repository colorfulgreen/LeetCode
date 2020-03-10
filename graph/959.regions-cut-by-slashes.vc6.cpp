#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(vector< vector<int> >& G, int i, int j) {
        if(i>=0 && i<G.size() && j>=0 && j<G.size() && G[i][j] == 0) {
            G[i][j] = 1;
            dfs(G, i-1, j); dfs(G, i+1, j); dfs(G, i, j-1); dfs(G, i, j+1);
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        vector< vector<int> > G(grid.size() * 3, vector<int>(grid.size()*3, 0));
        int regions = 0, i, j;
        for(i=0; i<grid.size(); i++) {
            for(j=0; j<grid.size(); j++) {
                if(grid[i][j] == '\\')
                    G[i*3][j*3] = G[i*3+1][j*3+1] = G[i*3+2][j*3+2] = 1;
                else if(grid[i][j] == '/')
                    G[i*3+2][j*3] = G[i*3+1][j*3+1] = G[i*3][j*3+2] = 1;
            }
        }

        for(i=0; i<G.size(); i++) {
            for(j=0; j<G.size(); j++) {
                if(G[i][j] == 0) {
                    dfs(G, i, j);
                    regions++;
                }
            }
        }

        return regions; 
    }
};

int main(void) {
    vector<string> grid;
    int regions;

    grid.push_back("/\\");
    grid.push_back("\\/");
    regions = Solution().regionsBySlashes(grid);
    cout << regions << endl;
    return 0;
}
