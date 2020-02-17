#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STACK {
    int sp;
    char values[200];
} Stack;

Stack *createStack(void) {
    Stack *s = malloc(sizeof(Stack));
    s->sp = 0;
    return s;
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

int minAddToMakeValid(char * S){
    int add = 0;
    Stack *stack = createStack();
    for(int i=0; i<strlen(S); i++) {
        switch(S[i]) {
            case '(':
                push(stack, '(');
                break;
            case ')':
                if(top(stack) == '(')
                    pop(stack);
                else
                    add++;
                break;
        }
    }
    while(top(stack) != '\0') {
        pop(stack);
        add++;
    }

    return add;
}

int main(void) {
    int r = minAddToMakeValid("(())");
    printf("%d\n", r);
    return 0;
}


