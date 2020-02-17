#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct STACK {
    int sp;
    char values[201];
} Stack;

Stack *createStack(void) {
    Stack *s = malloc(sizeof(Stack));
    s->sp = 0;
    return s;
}

void push(Stack *stack, char c) {
    stack->values[stack->sp++] = c;
}

void pop(Stack *stack) {
    if(stack->sp != 0)
        stack->sp--;
}


char *simplify(char *str) {
    Stack *stack = createStack();
    for(int i=0; i<strlen(str); i++) {
        if(str[i] == '#')
            pop(stack);
        else
            push(stack, str[i]);
    }
    push(stack, '\0');
    return stack->values;
}

bool backspaceCompare(char * S, char * T){
    char *simplifyS = simplify(S);
    char *simplifyT = simplify(T);
    if(strcmp(simplifyS, simplifyT) == 0)
        return true;
    else
        return false;
}

int main(void) {
    bool r = backspaceCompare("ab##", "c#d#a");
    printf("%d\n", r);
    return 0;
}
