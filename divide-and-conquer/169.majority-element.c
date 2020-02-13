#include <stdlib.h>
#include <stdio.h>


//n = 5  0 1 2 3 4   len=5/2 start=5/2+1
//n = 6  0 1 2 3 4 5 

int majorityElementDivide(int *nums, int lo, int hi) {
    if(lo == hi)
        return nums[lo];

    /* divide and conquer */
    int leftMajor, rightMajor;
    int mid = lo + (hi-lo) / 2;
    leftMajor = majorityElementDivide(nums, lo, mid);
    rightMajor = majorityElementDivide(nums, mid+1, hi);
    if(leftMajor == rightMajor)
        return leftMajor;

    /* 左右 majority 不同，需要扫一轮以计数 */
    int leftCount=0, rightCount=0;
    for(int i=lo; i<=hi; i++) {
        if(nums[i] == leftMajor)
            leftCount++;
        else if(nums[i] == rightMajor)
            rightCount++;
    }
    return leftCount > rightCount ? leftMajor : rightMajor;
}

int majorityElement(int* nums, int numsSize){
    return majorityElementDivide(nums, 0, numsSize-1);
}

int main(void) {
    int nums[] = {47,47,72,47,72,47,79,47,12,92,13,47,47,83,33,15,18,47,47,47,47,64,47,65,47,47,47,47,70,47,47,55,47,15,60,47,47,47,47,47,46,30,58,59,47,47,47,47,47,90,64,37,20,47,100,84,47,47,47,47,47,89,47,36,47,60,47,18,47,34,47,47,47,47,47,22,47,54,30,11,47,47,86,47,55,40,49,34,19,67,16,47,36,47,41,19,80,47,47,27};
    int numsSize = sizeof(nums) / sizeof(int);
    int majority = majorityElement(nums, numsSize);
    printf("majority=%d\n", majority);
    return 0;
}

