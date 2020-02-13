#include <stdio.h>
#include <stdlib.h>

int *profitLog = NULL;

int rob(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    if(numsSize == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];
    if(profitLog == NULL) {
        profitLog = malloc(sizeof(int) * (numsSize+1));
        for(int i=0; i<numsSize+1; i++)
            profitLog[i] = -1;
    }
    if(profitLog[numsSize] != -1)
        return profitLog[numsSize];

    int profit0, profit1, profit;
    profit0 = nums[0] + rob(nums+2, numsSize-2);
    profit1 = nums[1] + rob(nums+3, numsSize-3);
    profit = profit0 > profit1 ? profit0 : profit1;
    profitLog[numsSize] = profit;
    return profit;
}

int main(void) {
    int nums[] = {2,7,9,3,1};
    int n = sizeof(nums) / sizeof(int);
    int profit;
    profit = rob(nums, n);
    printf("%d\n", profit);
    return EXIT_SUCCESS;
}
