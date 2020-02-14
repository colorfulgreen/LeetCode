#include <stdio.h>
#include <stdlib.h>


int minCostClimbingStairs(int* cost, int costSize){
    if(costSize == 0)
        return 0;
    if(costSize == 1)
        return cost[0];
    if(costSize == 2)
        return cost[0] + cost[1];
    for(int i=2; i<costSize; i++) {
        cost[i] += cost[i-1] < cost[i-2] ? cost[i-1] : cost[i-2];
    }
    return cost[costSize-1] < cost[costSize-2] ? cost[costSize-1] : cost[costSize-2];
}

int main(void) {
    int cost[] = {10, 15, 20};
    int costSize = sizeof(cost) / sizeof(int);
    int minCost = minCostClimbingStairs(cost, costSize);
    printf("%d\n", minCost);
    return 0;
}
