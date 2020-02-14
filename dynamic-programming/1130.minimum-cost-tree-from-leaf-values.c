#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int **record;

int maxLeaf(int *arr, int start, int end) {
    int max = 0;
    for(int i=start; i<end; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

/* Calculate the minimum cost in [start, end) */
int helper(int *arr, int start, int end) {
    if(start == end)
        return 0;
    if(start + 1 == end) /* donot add leaf */ 
        return 0;
    if(record[start][end] != -1)
        return record[start][end];

    int minCost = INT_MAX, cost;
    for(int i = start+1; i<end; i++) {
        cost = helper(arr, start, i) + helper(arr, i, end) + maxLeaf(arr, start, i) * maxLeaf(arr, i, end); 
        if(cost < minCost)
            minCost = cost;
    }
    printf("s=%d e=%d cost=%d\n", start, end, minCost);
    record[start][end] = minCost;
    return minCost;
}

int mctFromLeafValues(int* arr, int arrSize){
    record = malloc(sizeof(int *) * (arrSize+1));
    for(int i=0; i<arrSize+1; i++) {
        record[i] = malloc(sizeof(int) * (arrSize+1));
        for(int j=0; j<arrSize+1; j++) {
            record[i][j] = -1;
        }
    }

    return helper(arr, 0, arrSize);
}

int main(void) {
    int arr[] = {1,2,3,4,5};
    int cost = mctFromLeafValues(arr, sizeof(arr)/sizeof(int));
    printf("%d\n", cost);
    return 0;
}


