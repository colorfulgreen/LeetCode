#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void makeEmpty(Stack *s) {
    s->sp = 0;
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



char * minRemoveToMakeValid(char * s){
    int len = strlen(s);
    Stack *stack = createStack(len);
    char *r = malloc(sizeof(char) * (len+1));
    int pos = 0;
    for(int i=0; i<len; i++) {
        switch(s[i]) {
            case '(':
                push(stack, '(');
                r[pos++] = '(';
                break;
            case ')':
                if(top(stack) == '(') {
                    pop(stack);
                    r[pos++] = ')';
                }
                break;
            default:
                r[pos++] = s[i];
                break;
        }
    }
    r[pos] = '\0';
    pos--;
    puts(r);
    makeEmpty(stack);
    for(int i=pos; i>=0; i--) {
        switch(r[i]) {
            case ')':
                push(stack, ')');
                r[pos--] = ')';
                break;
            case '(':
                if(top(stack) == ')') {
                    pop(stack);
                    r[pos--] = '(';
                }
                break;
            default:
                r[pos--] = r[i];
                break;
        }
    }
    return r + pos + 1;
}


int main(void) {
    char *s = "a)b(c)d(";
    char *r = minRemoveToMakeValid(s);
    puts(r);
    return 0;
}

