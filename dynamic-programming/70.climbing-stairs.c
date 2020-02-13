#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n){
    if(n == 0 || n == 1)
        return 1;
    int r = 0, prev1 = 1, prev2 = 1;
    for(int i=2; i<=n; i++) {
        r = prev1 + prev2;
        prev2 = prev1;
        prev1 = r;
    }
    return r;
}


int main(void) {
    int r = climbStairs(3);
    printf("%d\n", r);
    return 0;
}
