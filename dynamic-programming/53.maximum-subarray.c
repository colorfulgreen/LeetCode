#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int max, cur;
    max = cur = nums[0];
    for(int i=1; i<numsSize; i++) {
        if(cur < 0) /* NOTE 要放到 += nums[i] 之前 */
            cur = 0;
        cur += nums[i];
        if(cur > max)
            max = cur;
    }
    return max;
}

int main(void) {
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(nums) / sizeof(int);
    int r = maxSubArray(nums, n);
    printf("%d\n", r);
    return 0;
}
