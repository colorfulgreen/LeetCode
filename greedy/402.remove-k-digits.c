#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 用数组实现堆栈 */
char values[10002];
int sp = 0;

int empty() {
    return sp == 0 ? 1 : 0;
}

void push(char c) {
    /* 丢掉前导0 */
    printf("push %c\n", c);
    if(sp == 0 && c == '0')
        return;
    values[sp++] = c;
}

char top(void) {
    return values[sp-1];
}

void pop(void) {
    printf("pop %c\n", top());
    if(!empty()) {
        sp--;
    }
}

/* 用堆栈处理数组中间元素的删除 */
char *removeKdigits(char * num, int k){
    int len = strlen(num);
    sp = 0;
    if(k == 0)
        return num;
    if(k == len)
        return "0";

    int i = 0;
    push(num[i++]);
    while(k > 0 && i < len) {
        while(!empty() && num[i] < top() && k > 0) {
            pop();
            k--;
        }
        push(num[i]);
        i++;
    }
    while(i<len) {
        push(num[i++]);
    }
    while(k>0) {
        pop();
        k--;
    }

    values[sp] = '\0';
    return sp == 0 ? "0" : values; 
}

int main(void) {
#if 0
    char num[] = "10200";
    int k = 1;
    char num[] = "1432219";
    int k = 3;
#endif
    char num[] = "112";
    int k = 1;
#if 0
    char num[] = "10";
    int k = 1;
    char num[] = "1234567890";
    int k = 9;
#endif
    char *r = removeKdigits(num, k);
    puts(r);
    return 0;
}
