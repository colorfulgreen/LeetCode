#include "utils.h"

void insertionSort(int **intervals, int intervalsSize) {
    int i, j, *tmp;
    for(i=0; i<intervalsSize; i++) {
        tmp = intervals[i];
        for(j=i; j>0 && (intervals[j-1][0] > tmp[0] || (intervals[j-1][0] == tmp[0] && intervals[j-1][1] > tmp[1])); j--)
            intervals[j] = intervals[j-1];
        intervals[j] = tmp;
    }
}


int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    if(pointsSize == 0)
        return 0;
    if(pointsSize == 1)
        return 1;

    int start, end, shots = 1, *cur;
    insertionSort(points, pointsSize);
    start = points[0][0];
    end = points[0][1];
    for(int i=1; i<pointsSize; i++) {
        cur = points[i];
        if(cur[0] <= end) {
            start = cur[0];
            end = cur[1] < end ? cur[1] : end;
        } else {
            shots++;
            start = cur[0];
            end = cur[1];
        }
    }
    return shots;
}

int main(void) {
    char s[] = "[10,16], [2,8], [1,6], [7,12]";
    int pointsSize;
    int **points = input2D(s, 1000, &pointsSize);
    int shots;
    shots = findMinArrowShots(points, pointsSize, NULL);
    printf("%d\n", shots);
    return 0;

}

