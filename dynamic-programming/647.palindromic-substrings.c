#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int countSubstrings(char * s){
    int len = strlen(s);
    if(len == 0)
        return 0;

    /* Construct a two-dimensional state from one-dimensional data. */
    /* Record whether the substring between [i,j] is palindromic */
    int **DP = malloc(sizeof(int *) * len); 
    for(int i=0; i<len; i++) {
        DP[i] = malloc(sizeof(int) * len);
        DP[i][i] = 1;
        for(int j=i+1; j<len; j++)
            DP[i][j] = 0;
    }
    for(int i=0; i<len-1; i++)
        DP[i][i+1] = s[i] == s[i+1] ? 1 : 0;

    /* If s[low] == s[high] and s[low+1,high-1] is palindromic, then s[low,high] is palindromic. */
    int span, low, high;
    for(int span=2; span<=len-1; span++) {
        for(int low=0; low<=len-span-1; low++) {
            high = low + span;
            DP[low][high] = (s[low] == s[high]) && (DP[low+1][high-1]) == 1 ? 1 : 0;
        }
    }

    int count = 0;
    for(int i=0; i<len; i++) 
        for(int j=i; j<len; j++)
            count += DP[i][j];

    return count;
}


int main(void) {
    char *s = "aaa";
    int count = countSubstrings(s);
    printf("%d\n", count);
    return 0;
}
