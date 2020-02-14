#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MIN3(a,b,c) MIN(MIN(a,b), MIN(b,c))

int minFallingPathSum(int** A, int ASize, int* AColSize){
    for(int i=ASize-2; i>=0; i--) {
        A[i][0] += MIN(A[i+1][0], A[i+1][1]);
        for(int j=ASize-2; j>=1; j--) {
            A[i][j] += MIN3(A[i+1][j-1], A[i+1][j], A[i+1][j+1]);
        }
        A[i][ASize-1] += MIN(A[i+1][ASize-1], A[i+1][ASize-2]);
    }
    int minSum = INT_MAX;
    for(int j=0; j<ASize; j++)
        if(A[0][j] < minSum)
            minSum = A[0][j];
    
    return minSum;
}


int main(void) {
    int *A[] = {
        (int []){1,2,3},
        (int []){4,5,6},
        (int []){7,8,9},
    };
    int ASize = 3;
    int AColSize[] = {3,3,3};
    int sum = minFallingPathSum(A, ASize, AColSize);
    printf("%d\n", sum);
    return EXIT_SUCCESS;
}

