#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10000

typedef struct {
    int size;
    int front;
    int rear;
    int values[CAPACITY];
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter *c = malloc(sizeof(RecentCounter));
    c->size = 0;
    c->front = 1;
    c->rear = 0;
    return c;
}

int succ(RecentCounter *c, int i) {
    if(++i == CAPACITY)
        i = 0;
    return i;
}

void enqueue(RecentCounter *c, int v) {
    c->size++;
    c->rear = succ(c, c->rear);
    c->values[c->rear] = v; 
}

void dequeue(RecentCounter *c) {
    printf("dequeue front=%d\n", c->front);
    c->front = succ(c, c->front);
    c->size--;
}

int front(RecentCounter *c) {
    return c->values[c->front];
}

int recentCounterPing(RecentCounter* obj, int t) {
    enqueue(obj, t);
    while(obj->size > 0 && t - front(obj) > 3000)
        dequeue(obj);
    return obj->size;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/

int main(void) {
    RecentCounter *counter = recentCounterCreate();
    int count;
    for(int i=0; i<=10000; i++) {
        count = recentCounterPing(counter, i);
        printf("%d\n", count);
    }
    return 0;
}
