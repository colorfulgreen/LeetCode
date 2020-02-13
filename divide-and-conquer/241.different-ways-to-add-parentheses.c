#include <string.h>
#include "../utils.h"

#define MAX_SIZE 10000


int* diffWaysToComputeDivide(char * input, int* returnSize, int lo, int hi){
    int *results = malloc(sizeof(int) * MAX_SIZE);
    int *resultsL, *resultsR, sizeL, sizeR;
    int pos = 0;
    for(int i=lo; i<=hi; i++) {
        char ch = input[i];
        if(ch == '+' || ch == '-' || ch == '*') {
            resultsL = diffWaysToComputeDivide(input, &sizeL, lo, i-1);
            resultsR = diffWaysToComputeDivide(input, &sizeR, i+1, hi);
            for(int j=0; j<sizeL; j++) {
                for(int k=0; k<sizeR; k++) {
                    if(ch == '+')
                        results[pos++] = resultsL[j] + resultsR[k];
                    else if(ch == '-')
                        results[pos++] = resultsL[j] - resultsR[k];
                    else if(ch == '*')
                        results[pos++] = resultsL[j] * resultsR[k];
                    printf("(%s) %c (%s) = %d\n", strndup(input+lo, i-lo), ch, strndup(input+i+1, hi-i), results[pos-1]);
                }
            }
        }
    }
    if(pos == 0) {
        results[pos++] = atoi(strndup(input+lo, hi-lo+1));
    }
    *returnSize = pos;
    print1D(results, *returnSize);
    return results;
} 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diffWaysToCompute(char * input, int* returnSize){
    return diffWaysToComputeDivide(input, returnSize, 0, strlen(input)-1);
}


int main(void) {
    char *input = "1-2+3*4-5*6-7+8*9";
    int returnSize;
    int *results = diffWaysToCompute(input, &returnSize);
    print1D(results, returnSize);
    printf("%d\n", returnSize);
    return 0;
}
