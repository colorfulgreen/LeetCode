#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector< vector<int> >& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowsN(m, 0);
        vector<int> colsN(n, 0);
        int i,j, count = 0;
        for(i=0; i<m; i++) {
            for(j=0; j<n; j++) {
                rowsN[i] += grid[i][j];
                colsN[j] += grid[i][j];
            }
        }
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                if(grid[i][j] == 1 && (rowsN[i] > 1 || colsN[j] > 1))
                    count++;

        return count;
    }
};
