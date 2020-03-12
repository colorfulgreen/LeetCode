#include <stdlib.h>

void dfs(int **grid, int **dis, int N, int i, int j, int curDis) {
    int adj[4][2] = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}}; 
    int x, y, adjIndex;

    if(dis[i][j] != -1 && dis[i][j] <= curDis)
        return;

    dis[i][j] = curDis;
    for(adjIndex=0; adjIndex<4; adjIndex++) {
        x = adj[adjIndex][0]; y = adj[adjIndex][1];
        if(x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == 0)
            dfs(grid, dis, N, x, y, curDis+1);
    }
}

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int **dis = malloc(sizeof(int *) * gridSize);
    int i, j, maxDis = -1;
    for(i=0; i<gridSize; i++) {
        dis[i] = malloc(sizeof(int) * gridSize);
        for(j=0; j<gridSize; j++) {
            dis[i][j] = -1;
        }
    }

    for(i=0; i<gridSize; i++) {
        for(j=0; j<gridSize; j++) {
            if(grid[i][j] == 1)
                dfs(grid, dis, gridSize, i, j, 0);
        }
    }

    for(i=0; i<gridSize; i++) {
        for(j=0; j<gridSize; j++) {
            if(grid[i][j] == 0 && dis[i][j] > maxDis)
                maxDis = dis[i][j];
        }
    }

    return maxDis;
}
