#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** A, int ASize, int* returnSize){
    *returnSize = ASize;
    if(ASize == 0)
        return NULL;

    int **table = malloc(sizeof(int *) * ASize);
    int i, j, min_count, pos = 0;
    for(i=0; i<ASize; i++) {
        table[i] = malloc(sizeof(int) * 26);
        for(j=0; j<26; j++)
            table[i][j] = 0;
        for(j=0; j<strlen(A[i]); j++)
            table[i][A[i][j] - 'a'] += 1;
    }

    char **common = malloc(sizeof(char *) * MAX_SIZE);
    for(j=0; j<26; j++) {
        min_count = table[0][j];
        for(i=1; i<ASize; i++) {
            if(table[i][j] < min_count) {
                min_count = table[i][j];
                if(min_count == 0)
                    break;
            }
        }
        if(min_count > 0) {
            for(i = 0; i < min_count; i++) {
                common[pos] = malloc(sizeof(char) * 2);
                common[pos][0] = 'a' + j;
                common[pos][1] = '\0';
                pos++;
            } 
        }
    }
    *returnSize = pos;
    return common;
}


int main(void) {
    char *A[] = {
        (char *)"cool",
        (char *)"lock",
        (char *)"cook"
    };
    int ASize = 3;
    int returnSize;
    char **common = commonChars(A, ASize, &returnSize);
    for(int i = 0; i < returnSize; i++) {
        printf("%s\n", common[i]);
    }
    return 0;
}

