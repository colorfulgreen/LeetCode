#include "../utils.h"


#define DIS(a) ((a[0])*(a[0]) + (a[1])*(a[1]))

void swap(int **a, int **b) {
    int **tmp = malloc(sizeof(int *));
    *tmp = *a;
    *a = *b;
    *b = *tmp;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
    if(pointsSize == 0)
        return NULL;

    /* TODO 递归调用中 returnColumnSizes 的处理 */
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * K);
    for(int i=0; i<K; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    if(pointsSize == K) {
        *returnSize = K;
        return points;
    }

    int pivot = DIS(points[0]);
    int *tmp;
    int i = 1, j = pointsSize - 1;
    printf("> i=%d j=%d pivot=%d K=%d\n", i, j, pivot, K);
    while(i <= j) {
        for(; i<j && DIS(points[i]) < pivot; i++)
            ;
        for(; j>=i && DIS(points[j]) >= pivot; j--)
            ;
        if(i<j) 
            swap(&points[i], &points[j]);
        if(i >= j)
            break;
    }
    swap(&points[0], &points[j]);
    print2D(points, pointsSize);

    if(j==K) {
        *returnSize = j;
        return points;
    }
    if(j>K) {
        return kClosest(points, j, pointsColSize, K, returnSize, returnColumnSizes);
    } 
    if(j<K) {
        kClosest(points+j+1, pointsSize-j-1, pointsColSize, K-j-1, returnSize, returnColumnSizes);
        *returnSize = K;
        return points;
    }

    return NULL;
}

int main(void) {
    char s[] = "3,3],[5,-1],[-2,4";
    int pointsSize;
    int **points = input2D(s, 10, &pointsSize);
    int pointsColSize[] = {2};
    int K = 2;
    int returnSize;
    int *returnColumnSizes;
    int **closest = kClosest(points, pointsSize, pointsColSize, K, &returnSize, &returnColumnSizes);
    print2D(closest, returnSize);
    return 0;
}

