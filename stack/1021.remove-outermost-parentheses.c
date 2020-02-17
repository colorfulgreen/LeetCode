#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stack;
int sp;

void push(char v) {
    stack[sp++] = v;
}

int isEmpty() {
    return sp == 0;
}

char top(void) {
    if(!isEmpty())
        return stack[sp-1];
    return '\0';
}

void pop(void) {
    sp--;
}

char * removeOuterParentheses(char * S){
    stack = malloc(sizeof(char) * strlen(S));
    sp = 0;

    char *result = malloc(sizeof(char) * strlen(S));
    int pos = 0;
    for(int i=0; i<strlen(S); i++) {
        switch(S[i]) {
            case '(':
                push('(');
                if(sp != 1)
                    result[pos++] = S[i];
                break;
            case ')':
                if(top() == '(') 
                    pop();
                if(!isEmpty())
                    result[pos++] = S[i];
                break;
        }
    }
    result[pos++] = '\0';
    free(stack);
    return result;

}

int main(void) {
    char *S = "(()())(())(()(()))";
    char *result = removeOuterParentheses(S);
    puts(result);
    return 0;
}
