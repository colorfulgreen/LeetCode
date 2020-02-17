#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct Node {
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S) {
    return S->Next == NULL;
}

Stack CreateStack(void) {
    Stack S;
    S = malloc(sizeof(struct Node));
    if(S == NULL) {
        perror("Out of space!!!");
        exit(EXIT_FAILURE);
    }
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S) {
    if(S == NULL)
        perror("Must use CreateStack first.");
    else
        while(!IsEmpty(S))
            Pop(S);
}

void Push(ElementType X, Stack S) {
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL) {
        perror("Out of space!!!");
        exit(EXIT_FAILURE);
    } else {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top(Stack S) {
    if(!IsEmpty(S))
        return S->Next->Element;
    perror("Empty Stack.");
    return 0; /* Return value used to avoid warning. */
}

void Pop(Stack S) {
    PtrToNode FirstCell;
    if(!IsEmpty(S)) {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}
