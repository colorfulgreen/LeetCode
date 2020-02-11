#include <stdio.h>
#include <stdlib.h>

void print(int **people, int size) {
    for(int i=0; i<size; i++) 
        printf("[%d %d] ", people[i][0], people[i][1]);
    putchar('\n');
}


void insertionSort(int **people, int peopleSize) {
    int *tmp, i, j;
    for(i=0; i<peopleSize; i++) {
        tmp = people[i];
        for(j=i; j>0 && (people[j-1][0] < tmp[0] || (people[j-1][0] == tmp[0] && people[j-1][1] > tmp[1])); j--) {
            people[j] = people[j-1];
        }
        people[j] = tmp;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    /* NOTE returnSize 和 returnColumnSizes 两个参数的传递和内存申请 */
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * peopleSize);
    *returnSize = peopleSize;
    for(int i=0; i<*returnSize; i++) {
        (*returnColumnSizes)[i] = peopleColSize[i];
    }

    insertionSort(people, peopleSize);

    /* 考虑将 height 最小的人插入到已排序队列中
     * 1. 则插入位置即为 k
     * 2. 且因为插入 height 小于队列中所有人，故插入不影响原有排序。
     */
    int *tmp, i, j;
    for(i=0; i<peopleSize; i++) {
        if(people[i][1] == i) {
            continue;
        }
        tmp = people[i];
        for(j=i; j>tmp[1]; j--) /* 注意这里要用 tmp，因为 people[i] 已经被修改 */
            people[j] = people[j-1];
        people[j] = tmp;
    }

    return people;
}

int main(void) {
    int peopleSize = 6;
    int **people = malloc(sizeof(int *) * peopleSize);
    int data[][2] = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    for(int i=0; i<peopleSize; i++) {
        people[i] = data[i];
    }
    int peopleColSize[] = {2, 2, 2, 2, 2, 2};
    int returnSize, *returnColumnSizes, **rqueue;
    rqueue = reconstructQueue(people, peopleSize, peopleColSize, &returnSize, &returnColumnSizes);
    print(rqueue, peopleSize);
    return 0;
}

