#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

void print(int *nums, int numsSize) {
    for(int i=0; i<numsSize; i++)
        printf("%3d ", nums[i]);
    putchar('\n');
}

bool isPossible(int* nums, int numsSize){
    if(numsSize < 3)
        return false;

    /* NOTE 不能用 MAX_SIZE 做计数数组的长度，因为 nums 没有保证连续，可能有间断，如 1 2 3 6 7 8 */
    int numsCount[MAX_SIZE];
    int min = nums[0], i;
    for(i=0; i<MAX_SIZE; i++)
        numsCount[i] = 0;
    for(i=0; i<numsSize; i++) {
        numsCount[nums[i] - min]++;
    }

    int start = 0, end = 0;
    print(numsCount, MAX_SIZE);
    while(start < MAX_SIZE) {
        for(end=start+1; end<MAX_SIZE && numsCount[end] >= numsCount[end-1]; end++)
            ;
        if(end - start < 3)
            return false;
        /* NOTE 不能减去 numsCount[start]，bad case 1 1 2 2 3 3 3 4 4 5 5 
         * 在条件允许时，要尽可能寻找长的序列，以免将后方序列截断。
         */
        for(i=start; i<end; i++)  
            numsCount[i] -= 1;  
        for(; start<MAX_SIZE && numsCount[start]==0; start++)
            ;
        print(numsCount, MAX_SIZE);
    }
    return true;
}


int main(void) {
    int nums[] = {1,1,2,2,3,3,3,4,4,5,5};
    int numsSize = sizeof(nums) / sizeof(int);
    bool possible = isPossible(nums, numsSize);
    printf("%d\n", possible);
}
