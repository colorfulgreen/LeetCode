#include <stdlib.h>
#include <stdio.h>

typedef int bool;
#define false 0
#define true 1

bool dfs(int *arr, int arrSize, int *adjA, int *adjB, int start, int *visited) {
    if(start >= 0 && start < arrSize && !visited[start]) {
        visited[start] = 1;
        if(arr[start] == 0) 
            return true;
        if(dfs(arr, arrSize, adjA, adjB, adjA[start], visited) ||
                dfs(arr, arrSize, adjA, adjB, adjB[start], visited))
            return true;
    }
    return false;
}

bool canReach(int* arr, int arrSize, int start){
    int *adjA = malloc(sizeof(int) * arrSize);
    int *adjB = malloc(sizeof(int) * arrSize);
    int *visited = malloc(sizeof(int) * arrSize);
    int i;
    bool reach;

    for(i=0; i<arrSize; i++) {
        visited[i] = 0;
        adjA[i] = i - arr[i];
        adjB[i] = i + arr[i];
    }
    reach = dfs(arr, arrSize, adjA, adjB, start, visited);
    free(adjA); free(adjB); free(visited);
    return reach;
}

int main(void) {
    int arr[] = {3,0,2,1,2};
    int start = 2;
    int reach = canReach(arr, sizeof(arr)/sizeof(int), start);
    printf("%d\n", reach);
    return 0;
}

