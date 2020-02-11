#include <stdio.h>
#include <stdlib.h>

void print(int **people, int size) {
    for(int i=0; i<size; i++) 
        printf("[%d %d] ", people[i][0], people[i][1]);
    putchar('\n');
}

void insertionSort(int **intervals, int intervalsSize) {
    int i, j, *tmp;
    for(i=0; i<intervalsSize; i++) {
        tmp = intervals[i];
        for(j=i; j>0 && (intervals[j-1][0] > tmp[0] || (intervals[j-1][0] == tmp[0] && intervals[j-1][1] > tmp[1])); j--)
            intervals[j] = intervals[j-1];
        intervals[j] = tmp;
    }
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if(intervalsSize <= 1)
        return 0;

    insertionSort(intervals, intervalsSize);

    int count = 1, end, i = 0, j;
    end = intervals[0][1];
    for(i=1; i<intervalsSize; i++) {
        if(intervals[i][0] >= end) {
            count++;
            end = intervals[i][1];
        } else {
            /* 对 start 合法的 intervals，保留最小的 end 
             * test case: [[2,3],[3,50],[4,10],[11,20]]
             */
            end = intervals[i][1] > end ? end : intervals[i][1];
        }
    }
    return intervalsSize - count;
}


   /* 错误：对 start 合法的 intervals，保留了首次遇到的 end，而不是最小的 end
    * test case: [[2,3],[3,50],[4,10],[11,20]] */
#if 0
    int erase_count = 0, *sp, i, j;
    for(i=0; i<intervalsSize; ) {
        sp = intervals[i];
        printf("%d %d\n", sp[0], sp[1]);
        for(i=i+1; i<intervalsSize && intervals[i][0] < sp[1]; i++) {
            erase_count++;
        }
    }
    return erase_count;
}
#endif


int main(void) {
    int intervalsColSize[] = {2, 2, 2, 2};

    int intervalsSize = 0, a, b;
    int **intervals = malloc(sizeof(int *) * 1000);
    getchar();
    while(scanf("[%d,%d]", &a, &b) == 2) {
        intervals[intervalsSize] = malloc(sizeof(int) * 2);
        intervals[intervalsSize][0] = a;
        intervals[intervalsSize][1] = b;
        intervalsSize++;
        getchar();
    }
    int erase = eraseOverlapIntervals(intervals, intervalsSize, intervalsColSize);
    printf("%d\n", erase);
    return 0;
}
