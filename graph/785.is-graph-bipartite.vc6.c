#include <stdlib.h>
#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

#define C1 1
#define C2 2

bool paintColor(int **graph, int graphSize, int* graphColSize, int *color, int cur, int curColor) {
    int i;

    printf("..... cur=%d curColor=%d color=%d\n", cur, curColor, color[cur]);
    if(color[cur])
        return color[cur] == curColor;

    color[cur] = curColor;
    printf("cur=%d color=%d\n", cur, curColor);
    for(i=0; i<graphColSize[cur]; i++) {
        if(!paintColor(graph, graphSize, graphColSize, color, graph[cur][i], curColor == C1 ? C2 : C1))
            return false;
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize){
    int *color = malloc(sizeof(int) * graphSize);
    int i, ok;
    for(i=0; i<graphSize; i++) 
        color[i] = 0;

    for(i=0; i<graphSize; i++) {
        if(color[i])
            continue;
        ok = paintColor(graph, graphSize, graphColSize, color, i, C1);
        if(!ok)
            return false;
    }
    return true;
}

int main(void) {
    int data[][2] = {{1},{0,3},{3},{1,2}};
    int i, j;
    bool r;

    int graphSize = 4;
    int graphColSize[] = {1,2,1,2};
    int **graph = malloc(sizeof(int *) * graphSize);
    for(i=0; i<graphSize; i++) {
        graph[i] = malloc(sizeof(int) * graphColSize[i]);
        for(j=0; j<graphColSize[i]; j++)
            graph[i][j] = data[i][j];
    }

    r = isBipartite(graph, graphSize, graphColSize);
    printf("r=%d\n", r);
    return 0;

}

