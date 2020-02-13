#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

int cmp(const void *pa, const void *pb) {
    int a = *(int *)pa;
    int b = *(int *)pb;
    return a < b ? -1 : a > b ? 1 : 0;
}

int findKthLargest(int* nums, int numsSize, int k){
    int *karray = malloc(sizeof(int) * k); /* 记录当前的 k 个最大元素 */
    int i, j, num, tmp;

    /* 前 k 个元素放到长度为 k 的有序数组中 */
    for(i=0; i<k; i++) {
        karray[i] = nums[i];
    }
    qsort(karray, k, sizeof(int), cmp);

    /* 逐个插入剩下元素 */
    for(; i<numsSize; i++) {
        if(nums[i] <= karray[0])
            continue;
        num = nums[i];
        tmp = karray[0];
        for(j=1; j<k && karray[j] < num; j++)
            karray[j-1] = karray[j];
        karray[j-1] = num;
        print1D(karray, k);
    }
    return karray[0];
}

int main(void) {
    int nums[] = {3,2,1,5,6,4};
    int numsSize = sizeof(nums) / sizeof(int);
    int k = 2;
    int kth = findKthLargest(nums, numsSize, k);
    printf("%d\n", kth);
    return 0;
}
