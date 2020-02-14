#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixBlockSum(int** mat, int matSize, int* matColSize, int K, int* returnSize, int** returnColumnSizes){
    if(matSize == 0)
        return NULL;

    /* initialize returnColumnSizes and rM */
    *returnSize = matSize;
    *returnColumnSizes = (int *)malloc(sizeof(int) * matSize);
    for(int i=0; i<matSize; i++) {
        (*returnColumnSizes)[i] = matColSize[i];
    }
    int **dM = malloc(sizeof(int *) * matSize);
    int i, j;
    for(i=0; i<matSize; i++) {
        dM[i] = malloc(sizeof(int) * matColSize[i]);
        for(j=0; j<matColSize[i]; j++) {
            dM[i][j] = mat[i][j]; 
        }
    }

    /* build matrix for dynamic programming */
    dM[0][0] = mat[0][0];
    for(j=1; j<matColSize[0]; j++) {
        dM[0][j] += dM[0][j-1];
    }
    for(i=1; i<matSize; i++) {
        dM[i][0] += dM[i-1][0];
    }
    for(i=1; i<matSize; i++) {
        for(j=1; j<matColSize[0]; j++) {
            dM[i][j] += dM[i-1][j] + dM[i][j-1] - dM[i-1][j-1]; 
        }
    }
    printMatrix(dM, matSize, matColSize[0]);

    /* get result */
    int ri,rj,li,lj;
    int **rM = malloc(sizeof(int *) * matSize);
    for(i=matSize-1; i>=0; i--) {
        rM[i] = malloc(sizeof(int) * matColSize[i]);
        for(j=matColSize[i]-1; j>=0; j--) {
            ri = MIN(i+K, matSize-1);
            rj = MIN(j+K, matColSize[i]-1);
            li = i-K-1;
            lj = j-K-1;
            printf("%d ri=%d rj=%d li=%d lj=%d\n", dM[i][j], ri, rj, li, lj);
            rM[i][j] = dM[ri][rj];
            if(li >= 0)
                rM[i][j] -= dM[li][rj];
            if(lj >= 0)
                rM[i][j] -= dM[ri][lj];
            if(li >= 0 && lj >= 0)
                rM[i][j] += dM[li][lj];
        }
    }
    printMatrix(rM, matSize, matColSize[0]);
    return rM;
}


int main(void) {
    int *mat[] = {
        (int []){1,2,3},
        (int []){4,5,6},
        (int []){7,8,9},
        (int []){7,8,9}
    };
    int matSize = 4;
    int matColSize[] = {3,3,3,3};
    int K = 3;
    int returnSize;
    int *returnColumnSizes;
    int **rmatrix = matrixBlockSum(mat, matSize, matColSize, K, &returnSize, &returnColumnSizes);
    //print2D(rmatrix);
}
