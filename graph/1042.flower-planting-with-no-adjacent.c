#include <stdlib.h>
#include <stdio.h>

typedef struct LIST_ENTRY {
    int no;
    struct LIST_ENTRY *next;
} ListEntry;

typedef struct TABLE_ENTRY {
    int no;
    int color;
    ListEntry *header;
} TableEntry;

void appendList(TableEntry *entry, int no) {
    ListEntry *node = malloc(sizeof(ListEntry));
    ListEntry *p;
    node->no = no; node->next = NULL;
    if(entry->header == NULL) {
        entry->header = node;
    } else {
        p = entry->header;
        while(p->next != NULL)
            p = p->next;
        p->next = node;
    }
    return;
}

TableEntry *initTable(int N, int** paths, int pathsSize) {
    TableEntry *T = malloc(sizeof(TableEntry) * (N+1));
    int i;
    for(i=1; i<=N; i++) {
        T[i].no = i;
        T[i].color = -1;
        T[i].header = NULL;
    }
    for(i=0; i<pathsSize; i++) {
        appendList(&T[paths[i][0]], paths[i][1]);
        appendList(&T[paths[i][1]], paths[i][0]);
    }
    return T;
}

int hasAdjColor(TableEntry *T, ListEntry *header, int color) {
    while(header != NULL) {
        if(T[header->no].color == color)
            return 1;
        header = header->next;
    }
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* gardenNoAdj(int N, int** paths, int pathsSize, int* pathsColSize, int* returnSize){
    TableEntry *T = initTable(N, paths, pathsSize);
    int *colors = malloc(sizeof(int) * N);
    int v, c;
    for(v=1; v<=N; v++) {
        for(c=1; c<=4 && hasAdjColor(T, T[v].header, c); c++)
            ;
        T[v].color = c;
        colors[v-1] = c;
    }
    *returnSize = N;
    return colors;
}

int main(void) {
    int N = 4, pathsSize = 6;
    int **paths = malloc(sizeof(int *) * pathsSize);
    int i, returnSize;
    int *colors;
    FILE *f = fopen("1042_data.txt", "r");
    if(f == NULL) {
        perror("Open file failed.\n");
        exit(1);
    }
    for(i=0; i<pathsSize; i++) {
        paths[i] = malloc(sizeof(int) * 2);
        fscanf(f, "%d %d", &paths[i][0], &paths[i][1]);
    }

    colors = gardenNoAdj(N, paths, pathsSize, NULL, &returnSize);
    for(i=0; i<returnSize; i++) {
        printf("%d ", colors[i]);
    }

    return 0;
}
