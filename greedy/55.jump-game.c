#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize){
    if(numsSize == 1)
        return true;

    int maxReach = 0;   /* 记录每一阶段所能到达的最远的地方 */
    for(int i = 0; i < numsSize; i++) {
        if(i + nums[i] > maxReach)
            maxReach = i + nums[i];
        if(maxReach <= i)   /* 注意条件 <= */
            return false;
        else if(maxReach >= numsSize - 1)
            return true;
    }
    return false;
}


int main(void) {
  int nums[] = {3,2,1,0,4};
  bool r = canJump(nums, sizeof(nums)/sizeof(int));
  printf("%d\n", r);
  return EXIT_SUCCESS;
}


