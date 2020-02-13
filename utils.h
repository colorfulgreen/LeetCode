#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN 20

int **input2D(char *s, int maxSize, int *size) {
    char sep[] = "][";
    char *token = malloc(sizeof(char) * MAX_TOKEN);

    int **points = malloc(sizeof(int *) * maxSize);
    int _size = 0;
    int a,b;
    for(token = strtok(s, sep);
            token != NULL;
            token = strtok(NULL, sep)) {
        if(sscanf(token, "%d,%d", &a, &b) != 2)
            continue;
        points[_size] = malloc(sizeof(int) * 2);
        points[_size][0] = a;
        points[_size][1] = b;
        _size++;
    }
    *size = _size;
    return points;
}

void print2D(int **people, int size) {
    for(int i=0; i<size; i++) 
        printf("[%d %d] ", people[i][0], people[i][1]);
    putchar('\n');
}

void print1D(int *array, int n) {
    for(int i=0; i<n; i++)
        printf("%d ", array[i]);
    putchar('\n');
}
