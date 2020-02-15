#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 1000

bool backtracking(char *s, int i, char *p, int j) {
    if(i == 0 && j == 0)
        return true;
    if(i != 0 && j == 0)
        return false;
    if(i == 0 && j != 0) {
        if(p[j-1] == '*')
            /* p=c* matches empty string */
            return backtracking(s, i, p, j-2);
        return false;
    }

    if(s[i-1] == p[j-1] || p[j-1] == '.') {
        return backtracking(s, i-1, p, j-1);
    } else if(p[j-1] == '*') {
        /* p=c* matches empty string */
        if(backtracking(s, i, p, j-2))
            return true;
        if(s[i-1] == p[j-2] || p[j-2] == '.')
            /* p=bc* matches both s=b and s=bc, so we can simply remove c */
            return backtracking(s, i-1, p, j);
        return false;
    }

    return false;
}

bool isMatch(char * s, char * p){
    return backtracking(s, strlen(s), p, strlen(p));
}

int main(void) {
    char *s = malloc(sizeof(char) * BUFFER_SIZE);
    char *p = malloc(sizeof(char) * BUFFER_SIZE);
    while(scanf("%s %s", s, p) == 2) {
        int r = isMatch(s, p);
        printf("r=%d s=%s p=%s\n\n", r, s, p);
    }
    return 0;
}
