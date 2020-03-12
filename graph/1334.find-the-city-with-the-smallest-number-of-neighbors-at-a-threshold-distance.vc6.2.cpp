#include <vector>
using namespace std;

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
    int findTheCity(int n, vector< vector<int> >& edges, int distanceThreshold) {
        // vector< vector<int> > dis(n, vector(n, distanceThreshold+1));
        vector<int> A(n, -1);
        vector< vector<int> > dis(n, A);
        int i, j, k;
        int theCity = -1, minCount = n, count;

        // Floyd-Warshall algorithm
        for(i=0; i<n; i++)
            dis[i][i] = 0;
        for(i=0; i<edges.size(); i++) 
            dis[edges[i][0]][edges[i][1]] = dis[edges[i][1]][edges[i][0]] = edges[i][2];
        
        for(k=0; k<n; k++) 
            for(i=0; i<n; i++) {
                for(j=0; j<n; j++) {
                    if(dis[i][k] == -1 || dis[k][j] == -1)
                        continue;
                    dis[i][j] = dis[i][j] == -1 ? dis[i][k] + dis[k][j] : MIN(dis[i][k] + dis[k][j], dis[i][j]);
                }
            }
        
        for(i=0; i<n; i++) {
            count = 0;
            for(j = 0; j<n; j++) {
                if(dis[i][j] != -1 && dis[i][j] <= distanceThreshold)
                    count++;
            }
            if(count <= minCount) {
                minCount = count;
                theCity = i;
            }
        }
        
        return theCity;
        
    }
};
