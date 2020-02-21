#include <stdlib.h>
#include <stdio.h>

#define TABLE_SIZE 100000

typedef struct NODE {
    int key;
    int value;
    struct NODE *next;
} Node;

typedef struct {
    int size;
    Node **lists;
} MyHashMap;

int myHashMapGet(MyHashMap* obj, int key);

int nextPrime(int start) {
    for(; ; start++) {
        for(int i=2; i<=start/2; i++)
            if(start % i == 0)
                break;
        return start;
    }
}

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap *hashMap = malloc(sizeof(MyHashMap));
    hashMap->size = nextPrime(TABLE_SIZE);
    hashMap->lists = malloc(sizeof(Node *) * hashMap->size);
    for(int i=0; i<hashMap->size; i++) {
        hashMap->lists[i] = malloc(sizeof(Node));
        hashMap->lists[i]->next = NULL;
    }
    return hashMap;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    Node *head = obj->lists[key % obj->size];
    Node *node = head->next;
    while(node != NULL) {
        if(node->key == key) {
            node->value = value;
            return;
        }
    }
    node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = head->next;
    head->next = node;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    Node *node = obj->lists[key % obj->size];
    node = node->next; 
    while(node != NULL) {
        if(node->key == key)
            return node->value;
    }
    return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    if(myHashMapGet(obj, key) != -1) {
        Node *node = obj->lists[key % obj->size];
        Node *tmp;
        while(node->next != NULL) {
            if(node->next->key == key) {
                tmp = node->next;
                node->next = node->next->next;
                free(tmp);
            }
        }
    }
}

void myHashMapFree(MyHashMap* obj) {
    Node *node, *tmp;
    for(int i=0; i<obj->size; i++) {
        node = obj->lists[i];
        while(node->next != NULL) {
            tmp = node->next;
            node->next = node->next->next;
            free(tmp);
        }
        free(node);
    }
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
