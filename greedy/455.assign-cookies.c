#include <stdlib.h>
#include <stdio.h>

void insertionSort(int *a, int size) {
    int i, j, tmp;
    for(i=0; i<size; i++) {
        tmp = a[i];
        for(j=i; j>0 && a[j-1] > tmp; j--)
            a[j] = a[j-1];
        a[j] = tmp;
    }
}

int cmp(const void *ap, const void *bp) {
    int a = *(int *)ap;
    int b = *(int *)bp;
    return a < b ? -1 : a > b ? 1 : 0; 
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    int gp=0, sp=0, content=0;
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    for(gp=0; gp<gSize; gp++) {
        for(;sp<sSize;sp++) {
            if(s[sp] >= g[gp]) {
                content++;
                sp++;
                break;
            }
        }
    }

    return content;

}

int main(void) {
    int greed[] = {1,2,3};
    int greedSize = sizeof(greed) / sizeof(int);
    int size[] = {1,2,3};
    int sizeSize = sizeof(size) / sizeof(int);
    int content = findContentChildren(greed, greedSize, size, sizeSize);
    printf("%d\n", content);
    return 0;
}
