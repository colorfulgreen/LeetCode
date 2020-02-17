#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


char *infixToPostfix(char *infix) {
    int len = strlen(infix);
    char *postfix = malloc(sizeof(char) * len);
    Stack stack = CreateStack();
    int pos = 0;
    for(int i=0; i<len; i++) {
        switch(infix[i]) {
            case '+':
                while(!IsEmpty(stack) && (Top(stack) == '*' || Top(stack) == '+')) {
                    postfix[pos++] = Top(stack);
                    Pop(stack);
                }
                Push('+', stack);
                break;
            case '*':
                Push('*', stack);
                break;
            case '(':
                Push('(', stack);
                break;
            case ')':
                while(!IsEmpty(stack) && Top(stack) != '(') {
                    postfix[pos++] = Top(stack);
                    Pop(stack);
                }
                Pop(stack);
                break;
            default:
                postfix[pos++] = infix[i];
                break;
        }
    }
    while(!IsEmpty(stack)) {
        postfix[pos++] = Top(stack);
        Pop(stack);
    }
    return postfix;
}

int main(void) {
    char *infix = "a+b*c+(d*e+f)*g";
    char *postfix = infixToPostfix(infix);
    puts(postfix);
    return 0;
}
