#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int capacity;
    int size;
    int front;
    int rear;
    int *values;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *queue = malloc(sizeof(MyCircularDeque));
    queue->capacity = k;
    queue->size = 0;
    queue->front = 1; 
    queue->rear = 0;
    queue->values = malloc(sizeof(int) * k);
    return queue;
}

int succ(MyCircularDeque *obj, int i) {
    if(++i == obj->capacity)
        i = 0;
    return i;
}

int prev(MyCircularDeque *obj, int i) {
    if(--i == -1)
        i = obj->capacity - 1;
    return i;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(obj->size < obj->capacity) {
        obj->values[obj->front] = value;
        obj->front = succ(obj, obj->front);
        obj->size++;
        return true;
    } else {
        return false;
    }
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(obj->size < obj->capacity) {
        obj->values[obj->rear] = value;
        obj->rear = prev(obj, obj->rear);
        obj->size++;
        return true;
    } else {
        return false;
    }
  
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(obj->size > 0) {
        obj->front = prev(obj, obj->front);
        obj->size--;
        return true;
    } else {
        return false;
    }
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
     if(obj->size > 0) {
        obj->rear = succ(obj, obj->rear);
        obj->size--;
        return true;
    } else {
        return false;
    }
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(obj->size > 0) {
        return obj->values[prev(obj, obj->front)];
    }
    return -1;
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(obj->size > 0) {
        return obj->values[succ(obj, obj->rear)];
    }
    return -1;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->values);
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
