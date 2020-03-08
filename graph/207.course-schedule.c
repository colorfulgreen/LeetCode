#include <stdlib.h>
#include <stdbool.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int *indegree = malloc(sizeof(int) * numCourses);
    int i, j, course;

    for(i=0; i<numCourses; i++)
        indegree[i] = 0;
    for(i=0; i<prerequisitesSize; i++)
        indegree[prerequisites[i][1]] += 1;

    for(i=0; i<numCourses; i++) {

        /* find course of indgree 0  */
        for(j=0; j<numCourses; j++) {
            if(indegree[j] == 0) {
                course = j;
                indegree[j] = -1;
                break;
            }
        }
        if(j == numCourses)
            return false;

        for(j=0; j<prerequisitesSize; j++) {
            if(prerequisites[j][0] == course) {
                indegree[prerequisites[j][1]]--;
            }
        }
    }

    return true;
}


