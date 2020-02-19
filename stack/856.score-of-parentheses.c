#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct STACK {
    int sp;
    char *values;
} Stack;

Stack *createStack(int size) {
    Stack *s = malloc(sizeof(Stack));
    s->sp = 0;
    s->values = malloc(sizeof(char) * size);
    return s;
}

int stackSize(Stack *s) {
    return s->sp;
}

void push(Stack *s, char c) {
    s->values[s->sp++] = c;
}

char top(Stack *s) {
    if(s->sp != 0)
        return s->values[s->sp - 1];
    return '\0';
}

void pop(Stack *s) {
    if(s->sp != 0)
        s->sp--;
}

int scoreOfParentheses(char * S){
    int len = strlen(S);
    int score = 0;
    int record = 0;
    Stack *stack = createStack(len);
    for(int i=0; i<len; i++) {
        if(S[i] == '(') {
            push(stack, S[i]);
            record = 1;
        } 
        else if(S[i] == ')') {
            pop(stack);
            if(record) {
                score += pow(2, stackSize(stack));
            }
            record = 0;
        }
    }
    return score;
}

int main(void) {
    char *s = "(()(()))";
    int r = scoreOfParentheses(s);
    printf("%d\n", r);
    return 0;
}
