/* separate chaining 分离链接法 */

#include <stdio.h>
#include <stdlib.h>
#include "hashtable_separate_chaining.h"

#define MinTableSize 10

struct ListNode {
    ElementType Element;
    Position Next;
};

typedef Position List;
struct HashTbl {
    int TableSize;
    List *TheLists;
};

void FatalError(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int NextPrime(int i) {
    for(; ;i++) {
        int is_prime = 1;
        for(int j=2; j<=i/2; j++) {
            if(i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if(is_prime)
            return i;
    }
}

int Hash(const char *Key, int TableSize) {
    unsigned int HashVal = 0;
    while(*Key != '\0')
        HashVal = (HashVal << 5) + *Key++;
    return HashVal % TableSize;
}

HashTable InitializeTable(int TableSize) {
    HashTable H;
    int i;

    if(TableSize < MinTableSize) {
        perror("Table size too small");
        return NULL;
    }

    H = malloc(sizeof(struct HashTbl));
    if(H == NULL)
        FatalError("Out of space!!!");

    H->TableSize = NextPrime(TableSize);
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if(H->TheLists == NULL) 
        FatalError("Out of space!!!");

    for(int i = 0; i < H->TableSize; i++) {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if(H->TheLists[i] == NULL) 
            FatalError("Out of space!!!");
        else 
            H->TheLists[i]->Next = NULL;
    }
    return H;
}

Position Find(ElementType Key, HashTable H) {
    Position P;
    List L;

    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    while(P!= NULL && P->Element != Key)
        P = P->Next;
    return P;
}

void Insert(ElementType Key, HashTable H) {
    Position Pos, NewCell;
    List L;

    Pos = Find(Key, H);
    if(Pos == NULL) {
        NewCell = malloc(sizeof(struct ListNode));
        if(NewCell == NULL) 
            FatalError("Out of space!!!");
        else {
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            L->Next = NewCell;
        }
    }
}
