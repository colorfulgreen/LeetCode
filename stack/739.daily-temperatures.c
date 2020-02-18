#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"


typedef struct STACK {
    int sp;
    int *values;
} Stack;

Stack *createStack(int size) {
    Stack *s = malloc(sizeof(Stack));
    s->sp = 0;
    s->values = malloc(sizeof(int) * size);
    return s;
}

int isEmpty(Stack *s) {
    return s->sp == 0;
}

void push(Stack *s, int v) {
    s->values[s->sp++] = v;
}

int top(Stack *s) {
    return s->values[s->sp - 1];
}

void pop(Stack *s) {
    s->sp--;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    /* 堆栈的应用：存储数组下标而非对应值 */
    Stack *stack = createStack(TSize);
    int *wait = malloc(sizeof(int) * TSize);
    *returnSize = TSize;
    for(int i=0; i<TSize; i++) {
        while(!isEmpty(stack) && T[top(stack)] < T[i]) {
            wait[top(stack)] = i - top(stack);
            pop(stack);
        }
        push(stack, i);
    }
    while(!isEmpty(stack)) {
        wait[top(stack)] = 0;
        pop(stack);
    }


    return wait;
}

int main(void) {
    int T[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int TSize = sizeof(T) / sizeof(int);
    int returnSize;
    int *wait = dailyTemperatures(T, TSize, &returnSize);
    print1D(wait, returnSize);
    return 0;
}
