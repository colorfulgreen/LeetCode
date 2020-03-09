#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define NotAVertex (-1)

typedef struct LIST_ENTRY {
    int adjVertex;
    int dist;
    struct LIST_ENTRY *next;
} ListEntry;

typedef struct TABLE_ENTRY {
    ListEntry *header;
    int known;
    int dist;
    int path;
} TableEntry;

TableEntry *initTable(int **times, int timesSize, int N, int K) {
    TableEntry *T = malloc(sizeof(TableEntry) * (N+1));
    ListEntry *edge, *p;
    int i;

    for(i=1; i<=N; i++) {
        T[i].header = NULL;
        T[i].known = 0;
        T[i].dist = INT_MAX;
        T[i].path = NotAVertex;
    }
    T[K].dist = 0;

    for(i=0; i<timesSize; i++) {
        edge = malloc(sizeof(ListEntry));
        edge->adjVertex = times[i][1];
        edge->dist = times[i][2];
        edge->next = NULL;

        if(T[times[i][0]].header == NULL)
            T[times[i][0]].header = edge;
        else {
            p = T[times[i][0]].header;
            while(p->next != NULL)
                p = p->next;
            p->next = edge;
        }
    }
    return T;
}

int findSmallestUnknownVertex(TableEntry *T, int N) {
    int minDist = INT_MAX, vertex = NotAVertex;
    int i;
    for(i=1; i<=N; i++) {
        if(T[i].known == 0 && T[i].dist <= minDist) {
            minDist = T[i].dist;
            vertex = i;
        }
    }
    return vertex;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K){
    TableEntry *T = initTable(times, timesSize, N, K);
    ListEntry *edge;
    int vertex, delay = -1, i;

    for(;;) {
        vertex = findSmallestUnknownVertex(T, N);
        if (vertex == NotAVertex)
            break;
        printf("vertex=%d\n", vertex);

        T[vertex].known = 1;
        edge = T[vertex].header;
        while(edge != NULL) {
            if(!T[edge->adjVertex].known && T[vertex].dist + edge->dist < T[edge->adjVertex].dist) {
                T[edge->adjVertex].dist = T[vertex].dist + edge->dist;
                T[edge->adjVertex].path = vertex;
                printf("adjVertex=%d dist=%d\n", edge->adjVertex, T[edge->adjVertex].dist);
            }
            edge = edge->next;
        }
    }

    for(i=1; i<=N; i++) {
        if(T[i].dist == INT_MAX) 
            return -1;
        if(T[i].dist > delay)
            delay = T[i].dist;
    }

    return delay;

}

int main(void) {
    int timesSize = 3, N = 4, K = 2;
    int **times = malloc(sizeof(int *) * timesSize);
    int timesColSize[] = {3, 3, 3};
    int i, delay;
    
    FILE *f;
    f = fopen("743_data.txt", "r");
    if(f == NULL) {
        perror("Open file failed\n");
        exit(1);
    }
 
    for(i=0; i<timesSize; i++) {
        times[i] = malloc(sizeof(int) * 3);
        fscanf(f, "%d %d %d", &times[i][0], &times[i][1], &times[i][2]);
    }

    delay = networkDelayTime(times, timesSize, timesColSize, N, K);
    printf("delay=%d\n", delay);
    return 0;


}


