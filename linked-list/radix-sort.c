#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N_BUCKETS 10

/* linked list */
typedef struct NODE {
    int v;
    struct NODE *next;
} Node;

void append(Node *header, int v) {
    Node *p = header;
    while(p->next != NULL) 
        p = p->next;
    p->next = malloc(sizeof(Node));
    p->next->v = v;
    p->next->next = NULL;
}

Node *create(void) {
    Node *header = malloc(sizeof(Node));
    header->next = NULL;
    return header;
}

Node *buckets[N_BUCKETS];

void radixSort(int *nums, int numsSize) {
    int radix, i, bindex, hasMultiBuckets = 1;
    Node *p;
    for(radix=0; hasMultiBuckets; radix++) {
        hasMultiBuckets = 0;
        for(i=0; i<N_BUCKETS; i++) {
            buckets[i] = NULL;
        }
        for(i=0; i<numsSize; i++) {
            bindex = (nums[i] / (int)pow(10, radix)) % 10;
            if(buckets[bindex] == NULL) {
                buckets[bindex] = create();
            }
            append(buckets[bindex], nums[i]);
            if(bindex > 0)
                hasMultiBuckets = 1;
        }
        i = 0;
        for(bindex=0; bindex < N_BUCKETS; bindex++) {
            p = buckets[bindex];
            while(p != NULL && p->next != NULL) {
                nums[i++] = p->next->v;
                p = p->next;
            }
        }
    }
}

int main(void) {
    int nums[] = {1, 5, 1, 1, 6, 4};
    int numsSize = sizeof(nums) / sizeof(int);
    radixSort(nums, numsSize);
    for(int i=0; i<numsSize; i++) {
        printf("%d ", nums[i]);
    }
    putchar('\n');
    return 0;
}


