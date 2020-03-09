#include <stdio.h>
#include <stdlib.h>

int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int *indegrees = malloc(sizeof(int) * (N+1));
    int *outdegrees = malloc(sizeof(int) * (N+1));
    int i;

    for(i=1; i<=N; i++) {
        indegrees[i] = 0;
        outdegrees[i] = 0;
    }
    for(i=0; i<trustSize; i++) {
		printf("%d\n", trust[i][0]);
        outdegrees[trust[i][0]]++;
        indegrees[trust[i][1]]++;
    }

    for(i=1; i<=N; i++)
        if(indegrees[i] == N-1 && outdegrees[i] == 0)
            return i;

    return -1;
}

int main(void) {
    int N = 2, r;
	int trustSize = 1;
	int trustColSize[] = {2};
    int **trust = malloc(sizeof(int *) * trustSize);
	trust[0] = malloc(sizeof(int) * 2);
	trust[0][0] = 1; 
	trust[0][1] = 2;

    
    r = findJudge(N, (int**)trust, trustSize, trustColSize);
    printf("%d\n", r);
    return 0;
}
