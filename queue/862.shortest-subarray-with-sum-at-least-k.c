#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
int shortestSubarray(int* A, int ASize, int K){
    if(ASize == 0)
        return -1;

    int shortest = INT_MAX;
    /* increasing queue, using size of ASize+1 */
    int *sum = malloc(sizeof(int) * (ASize+1));
    int *deque = malloc(sizeof(int) * (ASize+2));
    int front = 0, rear = 0;

    /*  sum[i] = sum of A[0,i) */
    sum[0] = 0; 
    for(int i=1; i<=ASize; i++) {
        sum[i] = sum[i-1] + A[i-1];
    }

    deque[front++] = 0;
    for(int i=0; i<=ASize; i++) {
        //printf("rear=%d front=%d\n", deque[rear], deque[front-1]);
        while(front>0 && sum[deque[front-1]] > sum[i])  /* 队列中只放可以作为 subarray 起点的下标，负数不作为起点 */
            front--;
        while(rear<front && sum[deque[rear]] <= sum[i] - K) {
            shortest = MIN(i - deque[rear], shortest);
            rear++;
        }
        deque[front++] = i;
    }

    return shortest == INT_MAX ? -1 : shortest;
}

int main(void) {
    int A[] = {1};
    int ASize = sizeof(A) / sizeof(int);
    int r = shortestSubarray(A, ASize, 1);
    printf("%d\n", r);
    return 0;
}


