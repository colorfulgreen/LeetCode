#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool searchMatrixDivide(int** matrix, int xlo, int ylo, int xhi, int yhi, int target) {
    printf("xlo=%d, ylo=%d, xhi=%d, yhi=%d, xmid=0, ymid=0\n", xlo, ylo, xhi, yhi);
    if(xlo > xhi || ylo > yhi)
        return false;
    if(xlo == xhi && ylo == yhi)
        return matrix[xlo][ylo] == target;

    int xmid = xlo + (xhi - xlo)/2, ymid = ylo + (yhi - ylo)/2;
    int found;
    if(matrix[xmid][ymid] == target) {
        found = true;
    } 
    else if(matrix[xmid][ymid] > target) {
        found = searchMatrixDivide(matrix, xlo, ylo, xhi, ymid-1, target);
        if(!found)
            found = searchMatrixDivide(matrix, xlo, ylo, xmid-1, yhi, target);
    } 
    else {
        found = searchMatrixDivide(matrix, xmid+1, ylo, xhi, yhi, target);
        if(!found)
            found = searchMatrixDivide(matrix, xlo, ymid+1, xmid, yhi, target);
    }
    return found;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    return searchMatrixDivide(matrix, 0, 0, matrixRowSize-1, matrixColSize-1, target);
}

int main(void) {
    /* NODE A 2D array is not an array of pointers */
#if 0
    int *matrix[] = {
      (int []){1,   4,  7, 8, 15},
      (int []){2,   5,  8, 12, 19},
      (int []){3,   6,  9, 16, 22},
      (int []){10, 13, 14, 17, 24},
      (int []){18, 21, 23, 26, 30}
    };
#endif
    int *matrix[] = {
            (int []){1,2,3,4,5},
            (int []){6,7,8,9,10},
            (int []){11,12,13,14,15},
            (int []){16,17,18,19,20},
            (int []){21,22,23,24,25}
    };
    int matrixRowSize = 5;
    int matrixColSize = 5;
    int target = 5;
    bool found = searchMatrix(matrix, matrixRowSize, matrixColSize, target);
    printf("%d\n", found);
    return EXIT_SUCCESS;
}
