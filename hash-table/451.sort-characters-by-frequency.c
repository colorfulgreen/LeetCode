#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNTER_SIZE 128

typedef struct NODE {
    int key;
    int count;
} Node;

void insertionSort(Node *nodes, int n) {
    int i, j;
    Node tmp;
    for(i=0; i<n; i++) {
        tmp = nodes[i];
        for(j=i; j>0 && nodes[j-1].count > tmp.count; j--)
            nodes[j] = nodes[j-1];
        nodes[j] = tmp;
    }
}

char * frequencySort(char * s){
    if (s == NULL)
        return NULL;
    int len = strlen(s);
    if(len == 0)
        return "";
    char *result = malloc(sizeof(char) * (len+1));
    Node counter[COUNTER_SIZE];
    for(int i=0; i<COUNTER_SIZE; i++) {
        counter[i].key = i;
        counter[i].count = 0;
    }
    for(int i=0; i<len; i++) {
        counter[s[i]].count++;
    }

    insertionSort(counter, COUNTER_SIZE);

    int pos = 0;
    for(int i=COUNTER_SIZE-1; i>=0; i--) {
        while(counter[i].count-- > 0) {
            result[pos++] = counter[i].key;
        }
    }
    result[pos] = '\0';

    return result;
}

int main(void) {
    char *s = "tree";
    char *result = frequencySort(s);
    puts(result);
    return 0;
}


