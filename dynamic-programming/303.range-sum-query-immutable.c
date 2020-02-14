#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int v;
} NumArray;

int *sums;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *array = malloc(sizeof(NumArray) * numsSize);
    sums = malloc(sizeof(int) * (numsSize+1));
    sums[0] = 0;
    for(int i=0; i<numsSize; i++) {
        array[i].v = nums[i];
        sums[i+1] = sums[i] + nums[i];
    }
    return array;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    return sums[j+1] - sums[i];
}

void numArrayFree(NumArray* obj) {
    free(obj);
    free(sums);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
