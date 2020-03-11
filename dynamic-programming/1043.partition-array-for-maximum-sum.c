#include <stdlib.h>
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSumAfterPartitioning(int* A, int ASize, int K){
    int *dp = malloc(sizeof(int) * ASize);
    int i, k, curMax;
    for(i=0; i<ASize; i++) {
        curMax = 0;
        for(k=1; k<=K && i-k+1>=0; k++) {
            curMax = MAX(curMax, A[i-k+1]);
            dp[i] = MAX(dp[i], (i-k>=0 ? dp[i-k] : 0) + curMax * k);
        }
    }
    return dp[ASize - 1];
}

int main(void) {
    int A[] = {1,15,7,9,2,5,10};
    int K = 3;
    int maxSum = maxSumAfterPartitioning(A, sizeof(A)/sizeof(int), K);
    printf("%d\n", maxSum);
    return 0;
}


