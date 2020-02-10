#include <stdio.h>
#include <stdlib.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int start, remain, i, pos;
    for(start=0; start<gasSize; ) {
        remain = 0;
        for(i=0; i<=gasSize; i++) {
            pos = (start+i) % gasSize;
            remain += gas[pos] - cost[pos];
            if(remain < 0)
                break;
        }
        if (remain >= 0)
            return start;

		/* 提升速度的关键在这一句，如果在 pos 处失败，下一个起始位置应该是 pos+1 */
        start += i + 1;
    }
    return -1;
}

int main(void)
{
    // int gas[] = {2,3,4};
    // int cost[] = {3,4,3};
    int gas[] = {1,2,3,4,5};
    int cost[] = {3,4,5,1,2};
    int size = sizeof(gas) / sizeof(int);
    int start = canCompleteCircuit(gas, size, cost, size);
    printf("%d\n", start);
}
