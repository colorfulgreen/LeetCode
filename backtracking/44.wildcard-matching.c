#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 1000

int **M;

/* return true if s[0:i) matches p[0:j) */
bool backtracking(char *s, int i, char *p, int j) {
    if(i==0 && j==0)
        return true;
    if(i!=0 && j==0)
        return false;
    if(M[i][j] != -1)
        return M[i][j];
    // printf("s=%s p=%s\n", s+i-1, p+j-1);
    if(i==0 && j!=0) {
        if(p[j-1] == '*')
            return backtracking(s, i, p, j-1);
        M[i][j] = false;
        return false;
    }

    bool match;
    if(s[i-1] == p[j-1] || p[j-1] == '?') {
        return backtracking(s, i-1, p, j-1);
    }
    else if(p[j-1] == '*') {
        for(int k=0; k<=i; k++) {
            match = backtracking(s, i-k, p, j-1);
            if(match) {
                M[i][j] = true;
                return true;
            }
        }
        M[i][j] = false;
        return false;
    }
    else {
        M[i][j] = false;
        return false;
    }
}

bool isMatch(char * s, char * p) {
    int slen = strlen(s), plen = strlen(p);
    M = malloc(sizeof(int *) * (slen+1));
    for(int i=0; i<=slen; i++) {
        M[i] = malloc(sizeof(int) * (plen+1));
        for(int j=0; j<=plen; j++) {
            M[i][j] = -1;
        }
    }
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
