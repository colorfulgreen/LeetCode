#include <stdio.h>
#include <stdlib.h>

int countSquares(int** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize == 0)
        return 0;

    int count = 0, found = 0;
    /* side 1 */
    for(int i=0; i<matrixSize; i++) {
        for(int j=0; j<matrixColSize[i]; j++) {
            count += matrix[i][j];
        }
    }

    /* look in a fixed direction and
     * use matrix(i,j) to record whether the square matrix starting from (i,j) have all ones.
     */
    for(int side=2; side<=matrixSize; side++) {
        int side_count = 0;
        for(int i=0; i<matrixSize-side+1; i++) {
            for(int j=0; j<matrixColSize[i]-side+1; j++) {
                if(matrix[i][j] == 1 && matrix[i][j+1] == 1 && matrix[i+1][j] == 1 && matrix[i+1][j+1] == 1) {
                    matrix[i][j] = 1;
                    side_count += 1;
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
        if(side_count == 0)
            break;
        count += side_count;
    }
    return count;
}


int main(void) {
    int *mat[] = {
        (int []){0,1,1,1},
        (int []){1,1,1,1},
        (int []){0,1,1,1},
    };
    int matSize = 3;
    int matColSize[] = {4,4,4};
    int count = countSquares(mat, matSize, matColSize);
    printf("%d\n", count);
    return 0;
}

