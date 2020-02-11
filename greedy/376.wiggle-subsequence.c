#include <stdio.h>
#include <stdlib.h>

int wiggleMaxLength(int* nums, int numsSize){
    if(numsSize <= 1)
        return numsSize;
    int length = 1, pos = 1, i;
    while(pos < numsSize) {
        /* bad case {0, 0} 
         * 相邻元素升降序处理：首先确认相等的情况如何处理 1. 等同于升序 2. 等同于降序 3. 须单独处理
         */
        for(; pos < numsSize && nums[pos] == nums[pos - 1]; pos++)
            ;
        for(i = pos; i < numsSize && nums[i] >= nums[i-1]; i++)
            ;
        // printf("pos=%d i=%d\n", pos, i);
        if (i != pos) {
            length += 1;
            pos = i;
        }
        for(; pos < numsSize && nums[pos] == nums[pos - 1]; pos++)
            ;
        for(i = pos; i < numsSize && nums[i] <= nums[i-1]; i++)
            ;
        if(i != pos) {
            length += 1;
            pos = i;
        }
    }
    return length;
}

int main(void) {
    int nums[] = {0, 1};
    int length = wiggleMaxLength(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", length);
    return 0;
}


