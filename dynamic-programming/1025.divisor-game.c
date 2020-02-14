#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool divisorGame(int N){
    bool *result = malloc(sizeof(int) * (N+1));
    for(int i=0; i<=N; i++)
        result[i] = false;
    for(int i=2; i<=N; i++) {
        for(int j=1; j<i; j++) {
            if(i%j==0 && result[i-j] == false) {
                result[i] = true;
                break;
            }
        }
    }
    return result[N]; 
}

int main(void) {
    int result = divisorGame(3);
    printf("%d\n", result);
    return 0;
}
